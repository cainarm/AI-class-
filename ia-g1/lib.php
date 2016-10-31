<?php
function imgToArray($img, $x, $y)
{
	
	$size = getimagesize($img);

	$arraySize = array('x' => $x, 'y'=>$y);

	$width = $size[1]/$arraySize['x'];

	$heigth = $size[0]/$arraySize['y'];


	$im = imagecreatefromstring(file_get_contents($img));


	$black = 0;
	$white = 0;

	$Array = array();

	for ($y = 0; $y < $arraySize['x']; $y++) 
	{
	    for ($x = 0; $x < $arraySize['y']; $x++) 
	    {

	      // calculates if the pixel group is more black or more white(sort of)

	        for ($i= $y * $width ; $i < floor($width * ($y + 1)) ; $i++) 
	        { 
	        	for ($j= $x * $heigth; $j < floor(($x  + 1) * $heigth) ; $j++) 
	        	{ 
	        		
	        		
	        		if(floor($j) < $size[0] && floor($i) < $size[1]){

	        			$rgb = imagecolorat($im, $j, $i);
	        			
	        			$r = ($rgb >> 16) & 0xFF;
	      				$g = ($rgb >> 8) & 0xFF;
	        			$b = ($rgb >> 0) & 0xFF;

	        	    	if ($r >= 200 && $g >= 200 && $b >= 200) {
	                   	 	$white++;
	               		} else {
	                    	$black++;
	                	}

	        		}else{
	        			$white++;
	        		}
	  


	        	}


	        }
	        ///////////////////
	        
	        if ($black > $white)
	            $Array[$y][$x] = 1;
	        else
	            $Array[$y][$x] = 0;

	            $black = 0;
	            $white = 0;

	             
	         
	       
	    }
	   

	}  
	return $Array; 

}
function printArray($array)
{

	for ($y = 0; $y < count($array); $y++) {
	    for ($x = 0; $x < count($array); $x++) {	             
	         
	      echo $array[$y][$x];
	    }
	   
	    echo "<br>";
	} 
}
function transfer($output){

	if($output <= 0){
		return 0;
	}
	if($output > 0){
		return 1; 
	}
}
function check($values)
{
	$x = 0;

	foreach($values as $value)
	{	

		if($value->output != $value->expected){
			return false;
		}
		$x++;
		
	}
	return true;
}
function getSum($value, $weights, $width, $heigth)
{
	$sum = 0;
	

	for ($y = 0; $y < $width; $y++) {
	    for ($x = 0; $x < $heigth; $x++) {	             
	       	$sum = (int) $sum + ((int) $value->input[$y][$x] * (int) $weights[$y][$x]);
	    }
	} 

	return $sum;
}

function train($values, $weights, $width, $heigth)
{
	$x = 0 ;

	while(!check($values, $weights)){

		$values[$x]->sum = getSum($values[$x], $weights, $width, $heigth);
		$values[$x]->output = transfer($values[$x]->sum);

		if($values[$x]->output != $values[$x]->expected){

			for($i = 0; $i < $width; $i++){
				for($j = 0; $j < $heigth; $j++){
					$weights[$i][$j] = (int) $weights[$i][$j] + 1 * ((int)$values[$x]->expected - (int)$values[$x]->output) * (int)$values[$x]->input[$i][$j];
				}

			}
		}

		if($x >= count($values) - 1){
			$x = 0;

		}else{

			$x++;
		}
	}	

	return array($values, $weights);
}

?>