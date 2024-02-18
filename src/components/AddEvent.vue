<template>
  <div class="add-event-container">
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

    <h1 class="add-event-title">Add Event</h1>
    <form @submit.prevent="submitForm" class="add-event-form">
      <div class="form-group">
        <label for="eventName">Event Name</label>
        <input type="text" class="form-control" v-model="eventName">
      </div>
      <div class="form-group">
        <label for="dueDate">Due Date</label>
        <input type="datetime-local" class="form-control" id="dueDate" v-model="dueDate" step="1" @input="formatDueDate">
      </div>
      <div class="form-group">
        <label for="eventDetails">Add Description</label>
        <textarea class="form-control" id="eventDetails" rows="3" v-model="eventDetails"></textarea>
      </div>
      <div class="form-group">
        <label for="eventLocation">Add Venue</label>
        <input type="text" class="form-control" id="eventLocation" v-model="eventLocation">
      </div>
      <div class="form-group">
        <label for="eventImage">Upload Image</label>
        <input type="file" class="form-control" id="eventImage" @change="onFileChange">
      </div>
      
      <button type="submit" class="btn btn-primary submit-btn">Post</button>
      <router-link to="/EventHomePage" class="btn btn-secondary cancel-btn">Cancel</router-link>
      <p v-if="errorMessage" class="error-message">{{ errorMessage }}</p>
      <p v-if="successMessage" class="success-message">{{ successMessage }}</p>
    </form>
  </div>
</template>

<script>
import axios from 'axios';

export default {
  data() {
    return {
      eventName: '',
      dueDate: '',
      eventDetails: '',
      eventImage: null,
      eventLocation: '',
      errorMessage: '',
      successMessage: '',
    };
  },
  methods: {
    navigateTo(route) {
        this.$router.push(route)
      },
    submitForm() {
      // Reset error and success messages
      this.errorMessage = '';
      this.successMessage = '';

      // Validate form fields
      if (!this.eventName || !this.dueDate || !this.eventDetails || !this.eventLocation || !this.eventImage) {
        this.errorMessage = 'Please fill in all fields.';
        return;
      }

      const formData = new FormData();
      formData.append('name', this.eventName);
      formData.append('date', this.dueDate);
      formData.append('description', this.eventDetails);
      formData.append('image', this.eventImage);
      formData.append('location', this.eventLocation);

      axios.post('http://localhost:8000/events/add_event/', formData, {
        headers: {
          'Content-Type': 'multipart/form-data'
        }
      })
        .then(response => {
          // handle success
          console.log(response);
          this.successMessage = "Event has been created and is waiting for approval. After approval, it will be available as an Upcoming Event.";
          setTimeout(() => {
            this.successMessage = '';
            this.$router.push('/EventHomePage');
          }, 5000); // After 5 seconds, return to the EventHomePage
        })
        .catch(error => {
          // handle error
          console.log(error);
          this.errorMessage = 'An error occurred while creating the event. Please try again later.';
        });
    },
    onFileChange(event) {
      this.eventImage = event.target.files[0];
    },
    formatDueDate() {
      const date = new Date(this.dueDate);
      const year = date.getFullYear();
      const month = date.getMonth() + 1 < 10 ? '0' + (date.getMonth() + 1) : date.getMonth() + 1;
      const day = date.getDate() < 10 ? '0' + date.getDate() : date.getDate();
      const hours = date.getHours() < 10 ? '0' + date.getHours() : date.getHours();
      const minutes = date.getMinutes() < 10 ? '0' + date.getMinutes() : date.getMinutes();
      const seconds = date.getSeconds() < 10 ? '0' + date.getSeconds() : date.getSeconds();
      this.dueDate = year + '-' + month + '-' + day + ' ' + hours + ':' + minutes + ':' + seconds;
    }
  }
};
</script>

<style scoped>
.add-event-container {
  display: flex;
  flex-direction: column;
  align-items: center;
  margin-top: 50px;
}

.add-event-form {
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

.error-message {
  margin-top: 10px;
  color: red;
  font-weight: bold;
  background-color: #E2F9E3;
  border: 1px solid rgb(233, 68, 68);
  border-radius: 5px;
  padding: 10px;
  text-align: center;
}

.success-message {
  margin-top: 10px;
  color: green;
  font-weight: bold;
  background-color: #E2F9E3;
  border: 1px solid #5ABD5C;
  border-radius: 5px;
  padding: 10px;
  text-align: center;
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
  .add-event-form {
    margin: 0 20px;
  }
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
