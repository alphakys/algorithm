<?php
    


//echo hexdec('49057962');
echo dechex('49057962');

    return;
//strive server connection fields
header('Content-Type: text/html; charset=utf-8');
$server = "211.253.30.245:11001";
$user = "strivemaster";
$pw = "strive00245";
$db = "strive";

$dsn = "mysql:host={$server};dbname={$db};";
$pdo = new PDO($dsn, $user, $pw);

$pdo->setAttribute(PDO::ATTR_EMULATE_PREPARES, false);
$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);


    try{


//perfectGym server authorization fields
        //$login=$_GET['login'];
        //$password=$_GET['password'];

        $login= 'nochichi@naver.com';
        $password= '4227';

        $url = "https://strive.perfectgym.com/Api/oauth/authorize";
//The data you want to send via POST
        $fields = [
            'username'      => $login,
            'password'      => $password,
            'grant_type'      => 'password'

        ];
        $fields_string = http_build_query($fields);
        $ch = curl_init();
        curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, 0);
        curl_setopt($ch,CURLOPT_URL, $url);
        curl_setopt($ch,CURLOPT_POST, true);
        curl_setopt($ch,CURLOPT_POSTFIELDS, $fields_string);
        curl_setopt($ch,CURLOPT_RETURNTRANSFER, true);
        $resultLogin = curl_exec($ch);
        if (!curl_errno($ch)) {
            switch ($http_code = curl_getinfo($ch, CURLINFO_HTTP_CODE)) {
                case 200:
//                    echo "perfect gym login success"."<br>";
                    $raw_data = success($resultLogin);
                    break;
                default:
                    echo'{"result":false, "details": "no data"}';
                    return;
            }
        }

        //user data line
        $user_data = json_decode($raw_data,TRUE);
        $values = $user_data['elements'][0];
        $userid=$login;
        $user_name=$values['firstName'].' '.$values['lastName'];
        $rfid=dechex((int)$values['cards'][0]['cardNumber']);
        $email=$values['email'];
        $phone=substr($values['phoneNumber'],0,12); //substr($values['phoneNumber'], -7);
        $birthday=substr($values['birthDate'], 0, 10);
        $gender=$values['sex'];
        $clubs_id=$values['homeClubId'];
        $photoUrl=$values['photoUrl'];
        $userStriveId=$values['id'];

        $isEmployee = $values['employee'];
        
        $employee_id = $isEmployee['employeeId'];

        if($employee_id>0){
            $is_supervisor = 1;
           
        }else{
            $is_supervisor = 0;
        }
    

        //check whether user is existing or user is not existing
        $sql_chk = "select userid from users where userid = '$userid'";
        $stmt_chk = $pdo->prepare($sql_chk);
        $stmt_chk->execute();
        $chk = $stmt_chk->rowCount();
        $stmt_chk->closeCursor();

        if($chk>0){

//            echo "existing user"."<br>";
            
            $password= '4227';
            $user_name = 'Paul Walker';
            //4227
            //This code is for updating user information because if perfect gym app data is changed, there is
            //no way to know that so we check always when user login
            $update_sql = "call update_at_login('$userid', '$user_name', '$rfid', '$email', 
                                            '$phone', '$birthday', '$gender', $clubs_id, '$photoUrl', '$password')";

            $stmt_up = $pdo->prepare($update_sql);
            $stmt_up->execute();
            $is_success = $stmt_up->rowCount();
            $result = $stmt_up->fetchAll(PDO::FETCH_ASSOC);
            $stmt_up-> closeCursor();

            if($is_success){
//                echo "updated"."<br>";
            }
            ////////////////////////////////////////////////
            ////////////////////////////////////////////////
            ////////////////////////////////////////////////
            //existing user please make login process
            ////////////////////////////////////////////////
            ////////////////////////////////////////////////
            ////////////////////////////////////////////////
        }else{

//            echo "No user in strive database so insert new user"."<br>";

            $sql_key = "select keypad from users";

            $stmt_key = $pdo->prepare($sql_key);
            $stmt_key->execute();
        
            $results = $stmt_key->fetchAll(PDO::FETCH_ASSOC);
            $stmt_key->closeCursor();

            //$keys;
//            $keys;
        
            for($i=0; $i<count($results);$i++){
                $keys[]= $results[$i]['keypad'];
            }
            
            //print_r($keys);
            for($i=-4; $i>=-7; $i--){
        
                $key_tmp=substr($phone, $i);
                
                $key_find = in_array($key_tmp, $keys, true);
                
                if(!$key_find){
                    $keypad = $key_tmp;
                    break;
                }
            
            }
        
            $height = 0;
            $weight = 0;
            $is_expert = 0;
            
            //$userid = $email = addslashes($email);
            
            
//            echo $userid."<br>".$user_name."<br>". $password."<br>".  $rfid."<br>". $email."<br>".
//            $phone."<br>". $birthday."<br>". $gender."<br>". $keypad."<br>". $height."<br>".
//            $weight."<br>". $clubs_id."<br>". $is_expert."<br>";
//
            //execute line
        
            $sql = "call tttt('$userid','$user_name', '$password', '$rfid','$email', '$phone', 
                                           '$birthday', '$gender', '$keypad', '$height', '$weight',
                                            $clubs_id, $is_expert,'$photoUrl', $is_supervisor)";
            $stmt_insert = $pdo->prepare($sql);
            $stmt_insert->execute();
            $cnt = $stmt_insert->rowCount();
            $stmt_insert->closeCursor();

            //echo $cnt;
            
        }

        $pdo = new PDO($dsn, $user, $pw);
        $pdo->setAttribute(PDO::ATTR_EMULATE_PREPARES, false);
        $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
        $sql = "select * from v_usersinfo where userid = '$login'";
        $stmt = $pdo->prepare($sql);
        $stmt->execute();
        $cnt =  $stmt->rowCount();
        $result = $stmt->fetchAll(PDO::FETCH_ASSOC);
        if ($cnt > 0) {
            echo  '{"result":';
            echo json_encode($result, JSON_UNESCAPED_UNICODE).',';
            echo '"login_data":'.$resultLogin.',';
            echo '"user_strive_id":'.$userStriveId;
            echo '}';
        } else {
            echo'{"result":false, "details": "no data"}';
        }
//
//
        $pdo =null;


    }catch (Exception $e) {
            
            echo '{"result":false, "details":'.$e->getMessage().'}';
            exit();
    }


//function area

function success($striveLoginResponse){
    $response = json_decode($striveLoginResponse,TRUE);

    $url = "https://strive.perfectgym.com/Api/Users/User";
    $post_fields = '';
    $headers = ['Content-Type: application/x-www-form-urlencoded',
                 'Authorization: Bearer '.$response['access_token'],
        ];
    $dat = cUrlGetData($url, $post_fields, $headers);
    return $dat;

}

function cUrlGetData($url, $post_fields = null, $headers) {
//    curl_close;
    $ch = curl_init();
    $timeout = 10;
    curl_setopt($ch, CURLOPT_URL, $url);

    if (!empty($post_fields)) {

        curl_setopt($ch, CURLOPT_POST, 2);
        curl_setopt($ch, CURLOPT_POSTFIELDS, $post_fields);
    }

    if (!empty($headers))
        curl_setopt($ch, CURLOPT_HTTPHEADER, $headers);
    curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, 0);
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, 2);
    curl_setopt($ch, CURLOPT_SSL_VERIFYHOST, 2);
    curl_setopt($ch, CURLOPT_CONNECTTIMEOUT, $timeout);
    $data = curl_exec($ch);

    if (curl_errno($ch)) {

        echo '{"result":false, "details":' . curl_error($ch).'}';
    }

    curl_close($ch);



    return $data;
}


?>


