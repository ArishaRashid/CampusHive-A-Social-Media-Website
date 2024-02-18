<template>
 
 <nav>
      <div class="logo">
        <img src= "https://static.vecteezy.com/system/resources/thumbnails/004/638/227/small/gold-color-beehive-honeycomb-logo-design-vector.jpg" alt="Italian Trulli">
      </div>
      <ul class="nav-links">
  <li @click="navigateTo('/home')"><a href="#">Home</a></li>
  <li @click="navigateTo('/homereview')"><a href="#">Reviews</a></li>
  <li @click="navigateTo('/homeresources')"><a href="#">Resources</a></li>
  <li><a href="#">Events</a></li>
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
<div class="events-homepage-container">
<div class="events-header">
  <h1 class="events-title">Upcoming Events</h1>
  <div class="events-buttons">
    <!-- <router-link to="/ViewMyEvents" class="view-event-button">View My Events</router-link> -->
    <router-link to="/AddEvent" class="create-event-button">Create New Event</router-link>
    <!-- <router-link to="/user-events" class="my-events-button">View Your Events</router-link> -->
  </div>
</div>

<div v-if="events.length > 0">
  <div class="events-list">
    <div class="event-card" v-for="event in events" :key="event.id">
      <div class="event-card-image">
        <img :src="event.image" :alt="event.name">
      </div>
      <div class="event-card-details">
        <h2 class="event-card-name">{{ event.name }}</h2>
        <p class="event-card-description">{{ event.description }}</p>
        <p class="event-card-date">Date: {{ event.date }}</p>
        <div class="event-card-buttons">
          <button v-if="!event.interested" class="interest-button" @click="incrementInterest(event)">Interested {{ event.interests }}
            <span class="interest-count" v-if="event.interests > 0">({{ event.interests }})</span></button>
          <button v-if="event.interested" class="not-interest-button" @click="decrementInterest(event)">Not Interested {{ event.interests }}
            <span class="interest-count" v-if="event.interests > 0">({{ event.interests }})</span></button>
          <!-- <button class="share-button">Share</button> -->
        </div>
      </div>
    </div>
  </div>
</div>

<div v-else>
  <div class="no-events-list">
    <div class="no-events-message">
      <div class="hexagon-container">
        <h2 class="no-events-title">Our hive is still buzzing, but no events to attend just yet 🐝</h2>
      </div>
    </div>
  </div>
</div>
</div>
</template>

<script>
import axios from 'axios';

export default {
data() {
return {
  events: [], // Initialize with an empty array
};
},
methods: {
  navigateTo(route) {
        this.$router.push(route)
      },


getEvents() {
  axios.get('http://localhost:8000/events/get_event/')
    .then((response) => {
      if (response.data.length > 0) {
        this.events = response.data;
        this.checkUserInterest();
      } else {
        this.events = []; // Set to an empty array if no events
      }
    })
    .catch((error) => {
      console.log(error);
    });
},
decrementInterest(event) {
  if (new Date(event.date) < new Date()) {
    // Handle error here
    return;
  }
  axios.post('http://localhost:8000/events/decrement_interest/', { name: event.name })
    .then((response) => {
      console.log(response.data);
      event.interested = false;
    })
    .catch((error) => {
      console.log(error);
    });
},
incrementInterest(event) {
  if (new Date(event.date) < new Date()) {
    // Handle error here
    return;
  }
  axios.post('http://localhost:8000/events/increment_interest/', { name: event.name })
    .then((response) => {
      console.log(response.data);
      event.interested = true;
    })
    .catch((error) => {
      console.log(error);
    });
},
checkUserInterest() {
  axios.post('http://localhost:8000/events/check_user/', { headers: { 'Content-Type': 'application/json' } })
    .then((response) => {
      console.log(response.data);
      const userInterests = response.data;
      this.events.forEach((event) => {
        event.interested = userInterests.includes(event.name);
      });
    })
    .catch((error) => {
      console.log(error);
    });
},
},
mounted() {
this.getEvents();
},
};
</script>

<style scoped>
.events-homepage-container {
display: flex;
flex-direction: column;
align-items: center;
}

.page-title {
font-size: 2.5rem;
font-weight: bold;
margin: 2rem 0;
color: #FFE066;
}

.events-container {
display: flex;
flex-wrap: wrap;
justify-content: center;
gap: 2rem;
}
.hexagon-container {
display: flex;
justify-content: center;
align-items: center;
margin-bottom: 16px;
}

/* Navigation styles */
  
  nav {
    display: flex;
    justify-content: space-between;
    align-items: center;
    padding: 20px;
    background-color: white;
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
  
  /* Footer styles */
  
  
  footer p {
    font-size: 18px;
    color: #000;
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


.no-events-message {
display: flex;
flex-direction: column;
justify-content: center;
align-items: center;
font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
color: #575757;
}

.no-events-message {
margin: 20px;
padding: 20px;
background-color: #f2f2f2;
border-radius: 10px;
text-align: center;
font-size: 1.2rem;
color: #333;
box-shadow: 0px 0px 10px rgba(255, 224, 102);
}



.event-card {
width: 300px;
background-color: #FFE066;
padding: 1rem;
border-radius: 10px;
box-shadow: 0px 4px 10px rgba(0, 0, 0, 0.2);
}

.event-card-title {
font-size: 1.5rem;
font-weight: bold;
color: #434343;
}

.event-card-description {
margin-top: 1rem;
font-size: 1rem;
color: #434343;
}

.event-card-date {
margin-top: 1rem;
font-size: 1rem;
color: #434343;
}

.event-card-interest {
margin-top: 1rem;
display: flex;
align-items: center;
}

.interest-count {
margin-left: 0.5rem;
font-size: 1rem;
font-weight: bold;
color: #434343;
}

.event-card-share {
margin-top: 1rem;
display: flex;
align-items: center;
}

.create-event-button {
position: fixed;
bottom: 2rem;
right: 2rem;
padding: 1rem 2rem;
font-size: 1rem;
font-weight: bold;
color: #fff;
background-color: #FFB347;
border: none;
border-radius: 0.5rem;
cursor: pointer;
}

.view-event-button {
position: fixed;
bottom: 6rem;
right: 2rem;
padding: 1rem 2rem;
font-size: 1rem;
font-weight: bold;
color: #fff;
background-color: #FFB347;
border: none;
border-radius: 0.5rem;
cursor: pointer;
}

.events-container {
display: grid;
grid-template-columns: repeat(auto-fit, minmax(300px, 1fr));
grid-gap: 2rem;
margin: 2rem;
}

.event-card {
display: flex;
flex-direction: column;
justify-content: space-between;
height: 100%;
padding: 1rem;
border: 1px solid #E8E8E8;
border-radius: 0.5rem;
box-shadow: 0px 4px 8px rgba(0, 0, 0, 0.1);
background-color: #FFF;
transition: all 0.2s ease-in-out;
cursor: pointer;
}

.event-card:hover {
transform: translateY(-5px);
box-shadow: 0px 8px 16px rgba(0, 0, 0, 0.2);
}

.event-card h2 {
font-size: 1.5rem;
font-weight: bold;
color: #434343;
}

.interest-button {
margin-left: 0.5rem;
padding: 0.5rem;
font-size: 1rem;
font-weight: bold;
color: #fff;
background-color: #FFB347;
border: none;
border-radius: 0.5rem;
cursor: pointer;
}
.not-interest-button {
margin-left: 0.5rem;
padding: 0.5rem;
font-size: 1rem;
font-weight: bold;
color: #fff;
background-color: #f3aaaa;
border: none;
border-radius: 0.5rem;
cursor: pointer;
}

.interest-button:hover,
.not-interest-button:hover {
background-color: #FFDB99;
}

.interest-count {
margin-left: 0.5rem;
font-size: 1rem;
font-weight: bold;
color: #434343;
}

.share-button {
margin-left: 0.5rem;
padding: 0.5rem;
font-size: 1rem;
font-weight: bold;
color: #fff;
background-color: #FFB347;
border: none;
border-radius: 0.5rem;
cursor: pointer;
}
.share-button:hover {
background-color: #FFDB99;
}
.event-card p {
font-size: 1rem;
color: #434343;
}

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
padding: 20px;
background-color: white;
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

/* Footer styles */


footer p {
font-size: 18px;
color: #000;
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









</style>