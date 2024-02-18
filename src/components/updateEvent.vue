<template>
 
    <nav>
      <div class="logo">
        <img src= "https://static.vecteezy.com/system/resources/thumbnails/004/638/227/small/gold-color-beehive-honeycomb-logo-design-vector.jpg" alt="Italian Trulli">
      </div>
      <ul class="nav-links">
  <li><a href="#">Home</a></li>
  <li @click="navigateTo('/resources')"><a href="#">Reviews</a></li>
  <li @click="navigateTo('/resources')"><a href="#">Resources</a></li>
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
    <div class="update-event-container">

    <h1 class="update-event-title">Update Event</h1>
    <form @submit.prevent="submitForm" class="update-event-form">
      <div class="form-group">
        <label for="eventName">Event Name</label>
        <input type="text" class="form-control" v-model="event.name" required>
      </div>
      <div class="form-group">
        <label for="dueDate">Due Date</label>
        <input type="datetime-local" class="form-control" id="dueDate" v-model="event.dueDate" step="1" @input="formatDueDate" required>
      </div>
      <div class="form-group">
        <label for="eventDetails">Add Description</label>
        <textarea class="form-control" id="eventDetails" rows="3" v-model="event.eventDetails" required></textarea>
      </div>
      <div class="form-group">
        <label for="eventLocation">Add Venue</label>
        <input type="text" class="form-control" id="eventLocation" v-model="event.eventLocation" required>
      </div>
      <div class="form-group">
        <label for="eventImage">Upload Image</label>
        <input type="file" class="form-control" id="eventImage" @change="onFileChange" required>
      </div>
      
      <button type="submit" class="btn btn-primary submit-btn">Apply Changes</button>
      <router-link to="/ViewMyEvents" class="btn btn-secondary cancel-btn">Cancel</router-link>

      <div v-if="errorMessage" class="error-message">{{ errorMessage }}</div>
      <div v-if="successMessage" class="success-message">{{ successMessage }}</div>
    </form>
  </div>
</template>

<script>
import axios from 'axios';

export default {
  props: {
    eventName: {
      type: String,
      required: true
    }
  },
  data() {
    return {
      event: {
        name: '',
        dueDate: '',
        eventDetails: '',
        eventImage: null,
        eventLocation: ''
      },
      successMessage: '',
      errorMessage: ''
    };
  },
  created() {
    this.getEventDetails(); // Fetch event details on component creation
  },
  methods: {
    getEventDetails() {
      axios
        .post('http://localhost:8000/events/get_eventsname/', {
          params: { name: this.eventName },
          headers: {
            'Content-Type': 'application/json'
          }
        })
        .then((response) => {
          const event = response.data;
          this.event = {
            name: event.name,
            dueDate: event.date,
            eventDetails: event.description,
            eventLocation: event.location
          };
        })
        .catch((error) => {
          console.log(error);
          if (error.response && error.response.status === 404) {
            this.errorMessage = 'Event not found.';
          } else {
            this.errorMessage = 'An error occurred while fetching event details.';
          }
        });
    },
    navigateTo(route) {
        this.$router.push(route)
      },
    submitForm() {
      const requestData = {
        name: this.event.name,
        date: this.event.dueDate,
        description: this.event.eventDetails,
        image: this.event.eventImage,
        location: this.event.eventLocation
      };

      axios
        .put('http://localhost:8000/events/update/', requestData)
        .then(() => {
          // handle success
          this.successMessage = 'Event has been updated.';
          setTimeout(() => {
            this.$router.push('/ViewMyEvents');
          }, 2000);
        })
        .catch((error) => {
          // handle error
          console.log(error);
          if (error.response && error.response.status === 404) {
            this.errorMessage = 'Event not found.';
          } else {
            this.errorMessage = 'An error occurred while updating the event.';
          }
        });
    },
    onFileChange(event) {
      this.event.eventImage = event.target.files[0];
    },
    formatDueDate() {
      const date = new Date(this.event.dueDate);
      const year = date.getFullYear();
      const month = (date.getMonth() + 1 < 10 ? '0' : '') + (date.getMonth() + 1);
      const day = (date.getDate() < 10 ? '0' : '') + date.getDate();
      const hours = (date.getHours() < 10 ? '0' : '') + date.getHours();
      const minutes = (date.getMinutes() < 10 ? '0' : '') + date.getMinutes();
      const seconds = (date.getSeconds() < 10 ? '0' : '') + date.getSeconds();

      const formattedDate = `${year}-${month}-${day}T${hours}:${minutes}:${seconds}`;

      this.event.dueDate = formattedDate;
    }
  }
};
</script>

<style scoped>
.update-event-container {
  display: flex;
  flex-direction: column;
  align-items: center;
  margin-top: 50px;
}

.update-event-form {
  display: flex;
  flex-direction: column;
  align-items: center;
  border: 2px solid #F5A623;
  border-radius: 15px;
  padding: 20px;
  background-color: #FFFFFF;
  box-shadow: 0px 0px 10px rgba(0, 0, 0, 0.25);
  max-width: 600px;
}

.submit-btn {
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

.cancel-btn {
  margin-top: 0.5rem;
  padding: 0.5rem;
  font-size: 1rem;
  font-weight: bold;
  color: #fff;
  background-color: #A9A9A9;
  border: none;
  border-radius: 0.5rem;
  cursor: pointer;
}

.form-group {
  width: 100%;
  margin-bottom: 20px;
}

label {
  font-size: 20px;
  margin-bottom: 10px;
}

input[type="text"], textarea, input[type="file"], input[type="datetime-local"] {
  width: 100%;
  padding: 10px;
  border-radius: 10px;
  border: none;
  background-color: #F5F5F5;
  font-size: 18px;
}

input[type="submit"] {
  background-color: #F5A623;
  color: #FFFFFF;
  border: none;
  border-radius: 10px;
  padding: 10px 20px;
  font-size: 18px;
  cursor: pointer;
}

input[type="submit"]:hover {
  background-color: #FFFFFF;
  color: #F5A623;
  border: 2px solid #F5A623;
}

@media (max-width: 767px) {
  .update-event-form {
    margin: 0 20px;
  }
}

.error-message {
  color: red;
  margin-top: 10px;
}

.success-message {
  color: green;
  margin-top: 10px;
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
