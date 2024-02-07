<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="css/bootstrap.min.css">
    <script type="text/javascript" src="jquery/jquery.min.js"></script>
    <title>Realtime Web Sensor</title>
    <script type="text/javascript">
        $(document).ready(function() {
            setInterval(function() {
                $('#check_sensor_hc_sr04').load('ceksensor_hc_sr04.php')
            }, 1000);
        });
        $(document).ready(function() {
            setInterval(function() {
                $('#check_sensor_DHT11').load('ceksensor_DHT11.php')
            }, 1000);
        });
    </script>
</head>

<body>
    <div class="container" style="text-align: center; padding-top: 10%; width: 500px">
        <h2>Jarak</h2>
        <div class="panel panel-default">
            <div class="panel-body">
                <h1> <span id="check_sensor_hc_sr04"></span> cm</h1>
            </div>
        </div>
    </div>
    <div class="container" style="text-align: center; padding-top: 10%; width: 500px">
        <h2>Suhu</h2>
        <div class="panel panel-default">
            <div class="panel-body">
                <h1> <span id="check_sensor_DHT11"></span> °C</h1>
            </div>
        </div>
    </div>
</body>

</html>