<?php
// Connect to database
$conn = mysqli_connect("localhost", "root", "", "websensor");
$value = $_GET['sensor'];

//update data in database from sensor
mysqli_query($conn, "UPDATE sensor_dht11 set nilai_sensor = '$value'");
