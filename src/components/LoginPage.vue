<template>
    <div class="login-form">
      <h1>Login</h1>
      <form>
        <div class="form-group">
          <label for="email">Email</label>
          <input type="email" id="email" v-model="email" required>
        </div>
        <div class="form-group">
          <label for="password">Password</label>
          <input type="password" id="password" v-model="password" required>
        </div>
        <div class="form-group">
          <button type="submit" class="btn btn-primary" @click.prevent="loginUser">Login</button>
        </div>
      </form>
    </div>
    <div id="error-message"></div>
  </template>
  
  <script>
import axios from 'axios';
import Cookies from 'js-cookie';

export default {
  name: 'LoginPage',
  data() {
    return {
      email: '',
      password: '',
    }
  },
  methods: {
    loginUser() {
      axios.post('http://localhost:8000/api/login/', {
        email: this.email,
        password: this.password
      })
      .then(response => {
        const token = response.data.jwt;
        Cookies.set('jwt', token); // Store the token in a cookie
        this.$router.push('/home');
      })
      .catch(error => {
        console.log(error);
        const errorMessage = document.getElementById("error-message");
        errorMessage.textContent = error.response.data.detail;
      })
    }
  }
}
</script>
  
  
  <style scoped>
    .login-form {
      margin: 50px auto;
      max-width: 400px;
      background-color: #f7f7f7;
      padding: 20px;
      border-radius: 5px;
    }
  
    h1 {
      font-size: 32px;
      margin-bottom: 20px;
    }
  
    label {
      font-weight: bold;
      margin-bottom: 5px;
      display: block;
    }
  
    .form-group {
      margin-bottom: 20px;
    }
  
    input[type="email"],
    input[type="password"] {
      width: 100%;
      padding: 12px 20px;
      margin: 8px 0;
      box-sizing: border-box;
      border: 2px solid #ccc;
      border-radius: 4px;
      font-size: 16px;
      resize: vertical;
    }
  
    button[type="submit"] {
      background-color: #4CAF50;
      color: white;
      padding: 12px 20px;
      border: none;
      border-radius: 4px;
      cursor: pointer;
    }
  
    button[type="submit"]:hover {
      background-color: #45a049;
    }
  </style>
  