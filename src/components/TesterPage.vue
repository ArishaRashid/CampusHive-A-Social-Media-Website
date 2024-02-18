


 <!-- <template>
<!DOCTYPE html>
<html>
<head>
	<title>Hero with Hexagon Grid</title>
	
</head>
<body>
	<div class="hero1">
		<div class="hexagon"></div>
		<div class="hexagon"></div>
		<div class="hexagon"></div>
		<div class="hexagon"></div>
		<div class="hexagon"></div>
		<div class="hexagon"></div>
		<div class="hexagon"></div>
		<div class="hexagon"></div>
		<div class="hexagon"></div>
		<div class="hexagon"></div>	
		<div class="hexagon"></div>
		<div class="hexagon"></div>
		<div class="hexagon"></div>
		<div class="hexagon"></div>	
		<div class="hexagon"></div>
		<div class="hexagon"></div>
		<div class="hexagon"></div>	
    <div class="hexagon"></div>
		<div class="hexagon"></div>
		<div class="hexagon"></div>
		<div class="hexagon"></div>
		<div class="hexagon"></div>
		<div class="hexagon"></div>
		<div class="hexagon"></div>
		<div class="hexagon"></div>
		<div class="hexagon"></div>
		<div class="hexagon"></div>	
		<div class="hexagon"></div>
		<div class="hexagon"></div>
		<div class="hexagon"></div>
		<div class="hexagon"></div>	
		<div class="hexagon"></div>
		<div class="hexagon"></div>
		<div class="hexagon"></div>	
	</div>
</body>
</html>


 </template>


<style>
		* {
			box-sizing: border-box;
			margin: 0;
			padding: 0;
		}
		
		body {
			font-family: Arial, sans-serif;
			font-size: 16px;
		}
		
		.hero1 {
			display: flex;
			flex-wrap: wrap;
			background-color: #f2f2f2;
			height: 100vh;
			align-items: center;
			justify-content: center;
			overflow: hidden;
		}
		
		.hexagon {
			position: relative;
			width: 100px;
			height: 115.47px;
			background-image: url("hexagon.svg");
			background-repeat: no-repeat;
			background-position: center;
			background-size: contain;
			margin: 16px; 
      margin-top: 0px;
		}
		
		.hexagon::before,
		.hexagon::after {
			content: "";
			position: absolute;
			z-index: -1;
			width: 100px;
			height: 115.47px;
			background-image: inherit;
			background-repeat: no-repeat;
			background-position: center;
			background-size: contain;
		}
		
		.hexagon::before {
			transform: rotateZ(60deg);
		}
		
		.hexagon::after {
			transform: rotateZ(-60deg);
		}
.hexagon:hover {
  background-image: url("hexagono.svg");

  }
</style> -->


<template>

<div class="containerrr">
		<div class="row">
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
      
		</div>
		<div class="row altline2">
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
      
		</div>
		<div class="row line2">
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
		</div>
		<div class="row altline3">
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
		</div>
		<div class="row line3">
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
		</div>
		<div class="row altline4">
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
		</div>
		<div class="row line4">
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
		</div>
		<div class="row altline5">
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
		</div>
		<div class="row line5">
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
		</div>
		<div class="row">
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
		</div>
		<div class="row">
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
		</div>
		<div class="row">
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
			<div class="hexagon"></div>
		</div>
	</div>
  
</template>


<style>
*{
			margin: 0;
			padding: 0;
			box-sizing: border-box;
		}
		body{
			min-height: 100vh;
		}
		.containerrr{
			position: relative;
			overflow: hidden;
			height: 100vh;
			animation: animate 4s linear infinite;
		}
		@keyframes animate{
			0%{
				filter: hue-rotate(10deg);
			}
			100%{
				filter: hue-rotate(20deg);
			}
		}
		.row{
			display: inline-flex;
			margin-left: -50px;
			margin-top: -32px;
			overflow: hidden;
		}
		.row:nth-child(even){
			margin-left: 1px;
		}
		.hexagon{
			position: relative;
			height: 110px;
			width: 100px;
			background: #ffffff;
			margin: 1px;
			clip-path: polygon(50% 0%, 100% 25%, 100% 75%, 50% 100%, 0% 75%, 0% 25%);
			transition: 2s;
		}
		.hexagon:before{
			content: '';
			position: absolute;
			top: 0;
			left: 0;
			width: 50%;
			height: 100%;
			pointer-events: none;
			background: rgba(247, 213, 62, 0.02);
		}
		.hexagon:hover{
			transition: 0s;
			background: rgb(255, 162, 0);
      cursor: alias;
		}
</style>



