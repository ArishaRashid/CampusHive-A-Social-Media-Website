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
    <div class="view-my-events-container">

    <h1 class="page-title">My Events</h1>
    <template v-if="events.length === 0">
      <div class="no-events-message">
        <div class="hexagon-container"></div>
        <h2 class="no-events-title">Looks like the hive is a bit empty - you haven't posted any events yet!🐝</h2>
      </div>
    </template>
    <template v-else>
      <div v-for="event in events" :key="event.id" class="event-card">
        <img :src="event.image" alt="event-image" class="event-card-image" />
        <div class="event-card-details">
          <h2 class="event-card-name">{{ event.name }}</h2>
          <p class="event-card-description">{{ event.description }}</p>
          <p class="event-card-date">{{ formatDate(event.date) }}</p>
          <div class="event-card-actions">
            <!-- // ViewMyEvents.vue --><router-link :to="{ name: 'updateEvent', params: { 'eventName': event.name }}" class="update-event-btn">Update</router-link>

            <!-- <router-link to="/updateEvent" class="update-event-btn">Update</router-link> -->
            <button @click="deleteEvent(event.name)" class="delete-event-btn">Delete</button>
          </div>
        </div>
      </div>
    </template>
  </div>
</template>
<script>
import axios from 'axios';

export default {
  data() {
    return {
      events: [],
    };
  },
  created() {
    this.getUserEvents();
  },
  methods: {
    getUserEvents() {
      axios
        .get('http://localhost:8000/events/getuserevents/')
        .then((response) => {
          this.events = response.data;
        })
        .catch((error) => {
          console.log(error);
        });
    },
    navigateTo(route) {
        this.$router.push(route)
      },
    deleteEvent(eventName) {
      const confirmDelete = window.confirm('Are you sure you want to delete this event?');
      if (confirmDelete) {
        axios
          .post(`http://localhost:8000/events/delete/`, { "name": eventName })
          .then(() => {
            this.getUserEvents();
          })
          .catch((error) => {
            console.log(error);
          });
      }
    },
    formatDate(dateString) {
      const options = { year: 'numeric', month: 'long', day: 'numeric' };
      return new Date(dateString).toLocaleDateString('en-US', options);
    },
  },
};
</script>


  
  <style scoped>
  .view-my-events-container {
    max-width: 800px;
    margin: 0 auto;
  }
  
  .page-title {
    text-align: center;
    margin-bottom: 2rem;
    font-size: 2rem;
    color: #f5a623;
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
    display: flex;
    margin-bottom: 2rem;
    border: 1px solid #f5a623;
    padding: 1rem;
    border-radius: 5px;
    background-color: #fff;
  }
  
  .event-card-image {
    width: 30%;
    margin-right: 1rem;
  }
  
  .event-card-details {
    width: 70%;
  }
  
  .event-card-name {
    margin-top: 0;
    margin-bottom: 1rem;
    font-size: 1.5rem;
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
  
  .event-card-actions {
    margin-top: 1rem;
    display: flex;
    justify-content: flex-end;
  }
  
  .update-event-btn {
    background-color: #f5a623;
    border: none;
    color:#fff;
padding: 0.5rem 1rem;
font-size: 1rem;
font-weight: bold;
margin-left: 1rem;
cursor: pointer;
}

.delete-event-btn {
background-color: #f56a6a;
border: none;
color: #fff;
padding: 0.5rem 1rem;
font-size: 1rem;
font-weight: bold;
margin-left: 1rem;
cursor: pointer;
}

.view-my-events-container {
background-color: #fff;
padding: 2rem;
border-radius: 0.5rem;
box-shadow: 0px 0px 10px 0px rgba(0, 0, 0, 0.1);
display: flex;
flex-direction: column;
align-items: center;
}

.event-card {
width: 100%;
margin-top: 2rem;
background-color: #fff;
padding: 1.5rem;
border-radius: 0.5rem;
box-shadow: 0px 0px 10px 0px rgba(0, 0, 0, 0.1);
display: flex;
justify-content: space-between;
align-items: center;
}

.event-card-details {
display: flex;
flex-direction: column;
}

.event-card-name {
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

.error-message {
color: #f56a6a;
margin-top: 1rem;
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
  