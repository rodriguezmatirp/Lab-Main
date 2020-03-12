<!-- <html>     <body> <form method="get" > Name: <input type="number" name="number"> <input type="submit" value="odd or even"> </form>
<?php if ($_GET) { // collect value of input field
$no = $_GET['number']; 
if (empty($no)) {                echo "Empty, Try once again!";     } 
else {            if (($no%2)==0) {         echo $no." is Even!";     } 
else {         echo $no." is Odd"; } }
} ?> </body> </html> -->
<!-- 
<html> <body> <form method="post" > Name: <input type="number" name="number"> <input type="submit" value="odd or even"> 
</form> <?php if ($_POST) { // collect value of input field 
$no = $_POST['number']; if (empty($no)) { echo "Empty, Try once again!"; } 
else { if (($no%2)==0) { echo $no." is Even!";    } 
else {      echo $no." is Odd"; } } } ?> </body> </html>

 -->

 <html>
     <body>
         <?php
            $cars = array("bmw","volvo","benz");
            echo $cars[0] . $cars[1];

         ?>
     </body>
 </html>