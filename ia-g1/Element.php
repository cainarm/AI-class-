<?php 

	class Element
	{
		public $input;
		public $expected;
		public $sum;
		public $output;

		public function __construct($input, $expected)
		{
			$this->input = $input;
			$this->expected = $expected;
			$this->sum = 0;
			$this->output = 0;
		}
	}



?>