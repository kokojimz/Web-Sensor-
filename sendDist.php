<?php
// Connect to database
$conn = mysqli_connect("localhost", "root", "", "websensor");
$value = $_GET['sensor'];

//update data in database from sensor
mysqli_query($conn, "UPDATE sensor_hc_sr04 set nilai_sensor = '$value'");
