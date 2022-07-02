<?php

require('db_connection.php');

$pdo = $phpdo;

try {

    $user_id = $_GET['user_id'];
    $method =  $_GET['method'];
    //$date =    $_GET['date'];
    
    if($method==0){
        $compare = percentData($pdo, $user_id);
        
        if($compare==0){
            echo '{"result": false}';
            return;
        }else{
            $report["percent_data"] = $compare;
            $report["score_data"] = scoreData($compare);
            $report["graph_data"] = graphData($pdo, $user_id);
            echo '{"result" : '.json_encode($report, true).'}';
        }

    }else if($method==1){
        
        $date =    $_GET['date'];
        
        $report["percent_data"] = get_dateData($pdo, $user_id, $date);
        $report["force_data"] = get_forceData($pdo, $user_id, $date);
        
        echo '{"result" : '.json_encode($report, JSON_UNESCAPED_UNICODE).'}';

    }else{
        
        if( get_dateList($pdo, $user_id) ==0){
            echo '{"result": false}';
        }else{
            echo '{"result" : '.json_encode(get_dateList($pdo, $user_id), JSON_UNESCAPED_UNICODE).'}';
        }

    }

$pdo = null;
} catch (Exception $e) {
    echo $e->getMessage();
    $pdo = null;
    exit();
}
   
function get_dateList($pdo, $user_id){

    $sql = "
    Select   date_format(workoutdate, '%Y-%m-%d') date
	from     ronfic.miniplus_measure_test
	where    users_id = ?
    group by date_format(workoutdate, '%Y-%m-%d')
    order by date desc;
    ";
    
    $stmt = $pdo->prepare($sql);
    $stmt->execute(array($user_id));
    
    $cnt = $stmt->rowCount();

    if(!$cnt){
        return 0;
    }else{
        $result = $stmt->fetchAll(PDO::FETCH_ASSOC);
        return $result;
    }
    
}

function get_dateData($pdo, $user_id, $date){
    
    if($date==0){
        $date_query = "";
    }else{
        $date_query = "and date_format(workoutdate, '%Y-%m-%d') = '".$date."'";
    }

    $sql = "
    select if( ((max(f)/min(f))-1)*100=0, null, concat(ROUND(((max(f)/min(f))-1)*100, 1), '%')) 'percent',  
		#ifnull(concat(ROUND(((max(f)/min(f))-1)*100, 1), '%'), '0') 'percent',
	   code,
	   workoutdate#, max(f), min(f), max(f)/min(f)

	from
	(
		select tb1.test_code, avg(avg_force) f, id, workoutdate,
			   substr(tb1.test_code,-3) num, substring_index(tb1.test_code, substr(tb1.test_code,-3),1) code

		from
		(
		Select *
		from ronfic.miniplus_measure_test
		where users_id = $user_id
		) tb1,

		(
		select max(workoutdate) date, test_code
		from miniplus_measure_test
		where users_id = $user_id 
        $date_query
        group by test_code

		)tb2

		where tb1.workoutdate = tb2.date and tb1.test_code = tb2.test_code
		group by test_code
	)tb3 

    group by code;
    ";
    
    $stmt = $pdo->prepare($sql);
    $stmt->execute();
    
    $cnt = $stmt->rowCount();

    if($cnt<1){
        return false;
    }else{
        
        $result = $stmt->fetchAll(PDO::FETCH_ASSOC);
        
        foreach($result as $key => $val){
            $gapPer = $val['percent'];
    
            if ($gapPer <=5)  {
                $test_grade = 'Good';
            }    
            else if($gapPer <= 15){
                $test_grade = 'Normal';
            }else{
                $test_grade = 'Bad';
            }
            $result[$key]['test_grade'] = $test_grade;
        }

        return $result;
    }
    
}


function scoreData($compare){

    $balance_arr = array();
    $sum = 0;
    foreach($compare as $val){
        $gapPer = $val['percent'];

        if ($gapPer <=5)  {
            $gapPerGradeInt = 100;
        }    
        else if($gapPer <= 40){
            $gapPerGradeInt = (int)(96 - 2 * $gapPer);
        }else{
            $gapPerGradeInt = 0;
        }
        
        $sum += $gapPerGradeInt;
        $balance_arr[$val['code']] = $gapPerGradeInt;
        
    }

    
    $total_score = (int)($sum/5);
    $total_arr['total_score'] = $total_score;

        if ($total_score >= 90) $ResultGrade = "A";
        else if ($total_score >= 80) $ResultGrade = "B";
        else if ($total_score >= 70) $ResultGrade = "C";
        else if ($total_score >= 60) $ResultGrade = "D";
        else if ($total_score >= 50) $ResultGrade = "E";
        else if ($total_score > 0) $ResultGrade = "F";

    $total_arr['total_grade'] = $ResultGrade;
    $total_arr['balance_score'] = $balance_arr;
   
    return $total_arr;

}

function graphData($pdo, $user_id){

    $sql = "select substring_index(group_concat(f order by workoutdate desc), ',', 4) 'force', test_code, 

                    case    when
                            substr(test_code,-3)  = '001' and (code = 'PUSH' or code = 'PULL' or code = 'ROT')
                            then 'left'
                            
                            when
                            substr(test_code,-3)  = '002' and (code = 'PUSH' or code = 'PULL' or code = 'ROT')
                            then 'right'     
                            
                            when
                            substr(test_code,-3)  = '001' and (code = 'UPCODE' or code = 'LOWCODE')
                            then 'front'
                            
                            when
                            substr(test_code,-3)  = '002' and (code = 'UPCODE' or code = 'LOWCODE')
                            then 'back'     
                    end 'position',
                    substring_index(group_concat(date_format(workoutdate, '%Y-%m-%d') order by workoutdate desc), ',', 4) date




                from
                (
                Select  workoutdate, round((avg(avg_force)),1) f ,substring_index(test_code, substr(test_code,-3), 1) 'code', 
                    test_code
                from ronfic.miniplus_measure_test 
                where users_id = $user_id 
                group by test_code, workoutdate
                )tb
                group by test_code;";

            $stmt = $pdo->prepare($sql);
            $stmt->execute();
            $cnt = $stmt->rowCount();
            
            if($cnt==0){
               
                return $cnt;
            }else{
                $result = $stmt->fetchAll(PDO::FETCH_ASSOC);
                return $result;
            }
                

}

function get_forceData($pdo, $user_id, $date){
    if($date==0){
        $date_query = "";
    }else{
        $date_query = "and date_format(workoutdate, '%Y-%m-%d') <= '".$date."'";
    }

    $sql = "
    Select  test_code,
		    substring_index(group_concat(f order by workoutdate desc),',',2) f
		    , substring_index(group_concat(date_format(workoutdate, '%Y-%m-%d') order by workoutdate desc),',',2) date,
        
        case    when
                            substr(test_code,-3)  = '001' and (code = 'PUSH' or code = 'PULL' or code = 'ROT')
                            then 'left'
                            
                            when
                            substr(test_code,-3)  = '002' and (code = 'PUSH' or code = 'PULL' or code = 'ROT')
                            then 'right'     
                            
                            when
                            substr(test_code,-3)  = '001' and (code = 'UPCODE' or code = 'LOWCODE')
                            then 'front'
                            
                            when
                            substr(test_code,-3)  = '002' and (code = 'UPCODE' or code = 'LOWCODE')
                            then 'back'     
                    end 'position'
        from
        (
            Select test_code, round((avg(avg_force)),1) f, workoutdate, 
                    substring_index(test_code, substr(test_code,-3), 1) 'code',
                    substr(test_code,-3) num
            from ronfic.miniplus_measure_test

            where users_id = $user_id 
            
            $date_query
            #and date_format(workoutdate, '%Y-%m-%d') <='$date'
            
            
            group by workoutdate, test_code
        )tb
        group by test_code;
    ";
    
    $stmt = $pdo->prepare($sql);
    $stmt->execute();
    $cnt = $stmt->rowCount();
   
    if($cnt>0){

        $result = $stmt->fetchAll(PDO::FETCH_ASSOC);
        return $result;

    }else{

        return false;
    }

}




function percentData($pdo, $user_id){

    $sql = "
    select if( ((max(f)/min(f))-1)*100=0, null, concat(ROUND(((max(f)/min(f))-1)*100, 1), '%')) 'percent' , code, 
	       workoutdate

	from
	(
		select tb1.test_code, avg(avg_force) f, id, workoutdate,
			   substr(tb1.test_code,-3) num, substring_index(tb1.test_code, substr(tb1.test_code,-3),1) code

		from
		(
		Select *
		from ronfic.miniplus_measure_test
		where users_id = $user_id
		) tb1,

		(
		select max(workoutdate) date, test_code
		from miniplus_measure_test
		where users_id = $user_id 
        group by test_code

		)tb2

		where tb1.workoutdate = tb2.date and tb1.test_code = tb2.test_code
		group by test_code
	)tb3 
	group by code;
    ";
    
    $stmt = $pdo->prepare($sql);
    $stmt->execute();
    $cnt = $stmt->rowCount();
   
    if($cnt>0){
        
        $result = $stmt->fetchAll(PDO::FETCH_ASSOC);
    
        foreach($result as $key => $val){
            $gapPer = $val['percent'];

            if ($gapPer <=5)  {
                $test_grade = 'Good';
            }    
            else if($gapPer <= 15){
                $test_grade = 'Normal';
            }else{
                $test_grade = 'Bad';
            }
            $result[$key]['test_grade'] = $test_grade;
        }

        return $result;
    }else{

        return 0;
    }

}   

/* 	
select code, group_concat(f order by f desc) , code, group_concat(num order by f desc),
	   if( ((max(f)/min(f))-1)*100=0, null, concat(ROUND(((max(f)/min(f))-1)*100, 1), '%')) 'percent',
       substring_index( group_concat(num order by f desc) , ',', 1 ),

	   case when substring_index( group_concat(num order by f desc) , ',', 1 ) ='001' and code in ('PULL' , 'PUSH' , 'ROT')
			then concat( '우측 ', if( ((max(f)/min(f))-1)*100=0, null, concat(ROUND(((max(f)/min(f))-1)*100, 1), '%')) , ' 약함')
            #else concat( '후면 ', if( ((max(f)/min(f))-1)*100=0, null, concat(ROUND(((max(f)/min(f))-1)*100, 1), '%')) , ' 약함')
            
            when substring_index( group_concat(num order by f desc) , ',', 1 ) ='001' and code in ('LOWCODE' , 'UPCODE')
			then concat( '후면 ', if( ((max(f)/min(f))-1)*100=0, null, concat(ROUND(((max(f)/min(f))-1)*100, 1), '%')) , ' 약함')
		
            when substring_index( group_concat(num order by f desc) , ',', 1 ) ='002' and code in ('PULL' , 'PUSH' , 'ROT')
			then concat( '좌측 ', if( ((max(f)/min(f))-1)*100=0, null, concat(ROUND(((max(f)/min(f))-1)*100, 1), '%')) , ' 약함')
			
            when substring_index( group_concat(num order by f desc) , ',', 1 ) ='002' and code in ('LOWCODE' , 'UPCODE')
			then concat( '전면', if( ((max(f)/min(f))-1)*100=0, null, concat(ROUND(((max(f)/min(f))-1)*100, 1), '%')) , ' 약함')
            
       end 'compare'   
from
(
	select  tb1.test_code, avg(avg_force) f, workoutdate,
			substr(tb1.test_code,-3) num, substring_index(tb1.test_code, substr(tb1.test_code,-3),1) code

			from
			(
			Select *
			from ronfic.miniplus_measure_test
			where users_id = 100002897
			) tb1,

			(
			select max(workoutdate) date, test_code
			from miniplus_measure_test
			where users_id = 100002897 
			group by test_code

			)tb2

			where tb1.workoutdate = tb2.date and tb1.test_code = tb2.test_code
	group by test_code
)tb    
group by code
;
 */