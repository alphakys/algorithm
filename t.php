<?php

$server = "211.253.30.245:11000";
$user = "ronficmaster";
$pw = "ronfic00245";
$db = "ronfic";


    $dsn = "mysql:host={$server};dbname={$db};";
    $phpdo = new PDO($dsn, $user, $pw);
    $phpdo->setAttribute(PDO::ATTR_EMULATE_PREPARES, false);
    $phpdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

    $pdo = $phpdo;

try {
    
    $sql = "  
    select id, workoutdate, test_code, avg_force, avg_speed, force_data, speed_data
    from miniplus_measure_test  
    
    where users_id = 100002926;
        ";

    $stmt = $pdo->prepare($sql);
    $stmt->execute();

    $result = $stmt->fetchAll(PDO::FETCH_ASSOC);

    print_r($result);
    
    //fopen('file.csv', 'w+');




} catch (Exception $e) {
    echo $e->getMessage();
    $pdo = null;
    exit();
}
$pdo = null;

?>

    