<?php
$con=mysqli_connect("localhost", "root", "TheGobby12");
@mysql_select_db("stocks") or die( "Unable to select database");
$res = mysql_query("SELECT table_name FROM information_schema.tables
 WHERE table_schema = 'stocks' ORDER BY table_name DESC;");
$table = mysql_fetch_row($res, MYSQL_NUM);
$query_string = "SELECT * FROM `" . $table[0] . "`";
$result = mysql_query($query_string) or die(mysql_error());
$stocks = array();
while($row = mysql_fetch_array($result, MYSQL_NUM)){
  array_push($stocks, $row);
}
$sort = $_GET["sort"];
switch ($sort) {
  case 'listnumber':
    $index = 0;
    break;
  case 'nameandsymbol':
    $index = 1;
    break;
  case 'volume':
    $index = 2;
    break;
  case 'price':
    $index = 3;
    break;
  case 'change':
    $index = 4;
    break;
  case 'percentchange':
    $index = 5;
    break;
  default:
    break;
}
if($sort){
  usort($stocks, function($a,$b) use ($index){
      return strnatcmp($a[$index], $b[$index]);
  });
}
if($index == 2 || $index == 5){
  $stocks = array_reverse($stocks, false);
}
mysql_close();
?>

<html>
<head>
  <title>Stocks</title>
</head>
<body>
  <table border="1">
    <tr>
      <td><a href="?sort=listnumber">Number</a></td>
      <td><a href="?sort=nameandsymbol">Name and Symbol</a></td>
      <td><a href="?sort=volume">Volume</a></td>
      <td><a href="?sort=price">Price</a></td>
      <td><a href="?sort=change">Change</a></td>
      <td><a href="?sort=percentchange">Percent Change</a></td>
    </tr>
    <?php foreach($stocks as $stock): ?>
      <tr>
        <td><?php echo $stock[0]; ?></td>
        <td><?php echo $stock[1]; ?></td>
        <td><?php echo $stock[2]; ?></td>
        <td><?php echo $stock[3]; ?></td>
        <td><?php echo $stock[4]; ?></td>
        <td><?php echo $stock[5]; ?></td>
      </tr>
    <?php endforeach; ?>

  </table>

</body>
</html>
