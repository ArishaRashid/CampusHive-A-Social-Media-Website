<template>
  <!DOCTYPE html>
  <html lang="en">
  <head>
    <meta charset="UTF-8">
    <title>CampusHive</title>
    <link rel="stylesheet" href="styles.css">
    <link href="https://fonts.googleapis.com/css2?family=Montserrat:wght@400;700&display=swap" rel="stylesheet">
  </head>
  <body>
    <nav>
      <div class="logo">
        <h1>CampusHive</h1>
        <!-- <img src="https://cdn4.iconfinder.com/data/icons/apiculture/500/yul55_24_honeycomb_business_logo_abstract_silhouette_food_pattern-512.png" alt="Your Logo Alt Text" /> -->
      </div>
      <ul class="nav-links">
  <li><a href="#">Home</a></li>
  <li @click="navigateTo('/homereview')"><a href="#">Reviews</a></li>
  <li @click="navigateTo('/homeresources')"><a href="#">Resources</a></li>
  <li @click="navigateTo('/EventHomePage')"><a href="#">Events</a></li>
  <li class="dropdown">
        <a href="#" @click="toggleDropdown">Account</a>
        <div class="dropdown-content">
          <ul>
            <li @click="navigateTo('/register')"><a href="#">Create a new account</a></li>
            <li @click="navigateTo('/login')"><a href="#">Login</a></li>
            <li @click="navigateTo('/logout')"><a href="#">LogOut</a></li>
          </ul>
        </div>
      </li>
</ul>

    </nav>
  
    <div class="hero-section">
    <div class="container">
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
      </div>

      <section class="about">
      <h2>About CampusHive</h2>
      <p>CampusHive is a platform that connects students with resources, events, and teacher reviews to help them succeed in school.</p>
    </section>
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
      </div>
      <!-- <div class="row line3">
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
      </div> -->
      <!-- <div class="row altline4">
        <div class="hexagon"></div>
        <div class="hexagon"></div>
        <div class="hexagon"></div>
        <div class="hexagon"></div>
        <div class="hexagon"></div>
        <div class="hexagon"></div>
        <div class="hexagon"></div>
        <div class="hexagon"></div>
      </div> -->

 
    </div>
  </div>
  
    <!-- <section class="about">
      <h2>About CampusHive</h2>
      <p>CampusHive is a platform that connects students with resources, events, and teacher reviews to help them succeed in school.</p>
    </section> -->
  
    <section class="features">
      <h2>Our Features</h2>
      <div class="grid-container">
        <div @click="navigateTo('/homereview')" class="grid-item">
          <img src="https://www.svgrepo.com/show/164852/customer-reviews.svg" alt="Bee Icon">
          <h3 @click="navigateTo('/reviews')"> Reviews</h3>
          <p>Read reviews from other students to help choose the right teacher for you.</p>
        </div>
        <div @click="navigateTo('/homeresources')" class="grid-item">
          <img src="https://www.svgrepo.com/show/486275/data-development-resource-library.svg" alt="Bee Icon">
          <h3 @click="navigateTo('/resources')">Resources</h3>
          <p>Access resources to help you excel in your classes and succeed in school.</p>
        </div>
        <div @click="navigateTo('/EventHomePage')" class="grid-item">
          <img src="https://www.svgrepo.com/show/503025/event.svg" alt="Bee Icon">
          <h3 @click="navigateTo('/events')">Events</h3>
          <p>Stay up to date with campus events and activities to get the most out of your college experience.</p>
        </div>
      </div>
    </section>
  
    <footer>
      <p>&copy; 2023 CampusHive</p>
    </footer>
  </body>
  </html>
  
  </template>
  
  
  <style>
  /* Global styles */
  
  * {
    margin: 0;
    padding: 0;
    box-sizing: border-box;
    font-family: 'Montserrat', sans-serif;
  }
  
  /* Navigation styles */
  
  nav {
    display: flex;
    justify-content: space-between;
    align-items: center;
    padding-top: 20px;
    padding-left: 20px;
    padding-right: 20px;
    padding-bottom: 55px;
    background-color: #F4EBD9;
    /* margin-bottom: 50px;  */

  }
  
  .logo img{
    width: 100px;
    height: auto;
  }
  
  .nav-links {
    display: flex;
  }
  
  .nav-links li {
    list-style: none;
    margin-left: 30px;
  }
  
  .nav-links a {
    text-decoration: none;
    color: #000;
    font-weight: bold;
    font-size: 20px;
    transition: color 0.3s ease;
  }
  
  .nav-links a:hover {
    color: #F2AF29;
  }



  
  /* Hero section styles */
  
  .hero {
    background-image: url('https://png.pngtree.com/background/20211217/original/pngtree-honey-geometric-yellow-honeycomb-background-picture-image_1576243.jpg');
    background-size: cover;
    background-position: center;
    height: 500px;
    display: flex;
    justify-content: center;
    align-items: center;
    text-align: center;
  }
  
  .hero-text {
    color: #27292f;
  }
  
  .hero-text h1 {
    font-size: 70px;
    margin-bottom: 20px;
  }
  
  .hero-text p {
    font-size: 30px;
    margin-bottom: 30px;
  }
  
  .cta {
    display: inline-block;
    padding: 10px 30px;
    background-color: #1ebaf3;
    color: #fff;
    font-size: 20px;
    font-weight: bold;
    text-decoration: none;
    border-radius: 5px;
    transition: background-color 0.3s ease;
  }
  
  .cta:hover {
    background-color: #F4EBD9;
    color: #000;
  }
  
  /* About section styles */
  
  .about {
    padding: 50px 0px;
    text-align: center;
    /* background-color: #ffffff; */
    z-index: 1;

  }
  
  .about h2 {
    font-size: 50px;
    margin-bottom: 30px;
  }
  
  .about p {
    font-size: 20px;
    line-height: 1.5;
  }
  
  /* Features section styles */
  
  .features {
    background-color: #F2AF29;
    padding: 100px 50px;
    text-align: center;
  }
  
  .features h2 {
    font-size: 50px;
    margin-bottom: 30px;
    color: #fff;
  }
  
  .grid-container {
    display: grid;
    grid-template-columns: repeat(3, 1fr);
    gap: 50px;
    margin-top: 50px;
  }
  
  .grid-item {
    background-color: #fff;
    padding: 50px;
    border-radius: 10px;
    box-shadow: 0px 0px 20px rgba(0, 0, 0, 0.1);
  }
  
  .grid-item img {
    width: 100px;
    height: auto;
    margin-bottom: 30px;
  }
  
  .grid-item h3 {
    font-size: 30px;
    margin-bottom: 20px;
    color: #000;
  }
  
  .grid-item p {
    font-size: 20px;
    line-height: 1.5;
    color: #666;
  }
  
  /* Footer styles */
  
  footer {
    background-color: #F4EBD9;
    padding: 20px;
    text-align: center;
  }
  
  footer p {
    font-size: 18px;
    color: #000;
  }






/* Dropdown Button */
.dropbtn {
  display: inline-block;
  color: white;
  text-align: center;
  text-decoration: none;
  padding-left: 1000px;

}

/* Dropdown Content (Hidden by Default) */
.dropdown-content {
  display: none;
  position: absolute;
  background-color: #f9f9f9;
  min-width: 160px;
  box-shadow: 0px 8px 16px 0px rgba(0,0,0,0.2);

  z-index: 1;

}

/* Links inside the dropdown */
.dropdown-content a {
  color: black;
  padding: 12px 12px;
  text-decoration: none;
  display: block;
}

/* Change color of dropdown links on hover */
.dropdown-content a:hover {background-color: #f1f1f1}

/* Show the dropdown menu on hover */
.dropdown:hover .dropdown-content {
  display: block;
  position: absolute;
  left:80%;

}

/* Change the background color of the dropdown button when the dropdown content is shown */
.dropdown:hover .dropbtn {
  background-color: #3e8e41;
}



.dropdown-content.right {
  right: 0;
}


.features .grid-item:hover {
    background-color: #1ebaf3;
  }






 
.hero-section {
  background-color: #ffffff;
  z-index: 0;

}

  







  
  
  </style>
  


  <script>
  export default {
    methods: {


      navigateTo(route) {
        this.$router.push(route)
      }

      
    }
  }
  </script>
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  