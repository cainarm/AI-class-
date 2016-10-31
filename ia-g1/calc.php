<?php 
	
	include 'lib.php';	
	include 'Element.php';

	$elements = array();

	$x = 100;
	$y = 100;

	$elements[0] = new Element(imgToArray('b.png',$x, $y),1);
	$elements[1] = new Element(imgToArray('b1.png',$x, $y),1);

	$elements[2] = new Element(imgToArray('a.png',$x, $y),0);
	$elements[3] = new Element(imgToArray('a1.png',$x, $y),0);


	$weights = array();

	for($i = 0; $i < $x; $i++){
		for($j =0; $j < $y; $j++){
			$weights[$i][$j] = -1;
		}
	}


	$results = train($elements, $weights, $x, $y);
	$elements[4] = new Element(imgToArray($_GET['img'],$x, $y),0);

	$sum = getSum($elements[4], $results[1], $x, $y);
	$transfer = transfer($sum);

	if($transfer == 0)
		echo "its the letter A !";
	else if($transfer == 1)
		echo "its the letter B !";
	else 
		echo "not recognized !";
?>