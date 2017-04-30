<?php             
  echo "name of the event = ";
  echo $_POST['name'];
  echo ",\n device_id =";
  echo $_POST['device_id'];
  echo ",\n number of intruders = ";
  echo $_POST['value'];
  echo ",\n time = ";
  echo $_POST['time'];

  $msg = "I detected an intruder, check on the page https://photon.altervista.org/alarm.html \n\n name of the event = ". $_POST['name']. ",\n device_id =". $_POST['device_id']. ",\n number of intruders = ".  $_POST['value'].  ",\n time = " . $_POST['time'];
  mail("pasquini.1547849@studenti.uniroma1.it","Alarm",$msg);
?>