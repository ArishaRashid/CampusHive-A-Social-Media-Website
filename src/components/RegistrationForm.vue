<!-- <template>
  <div>
    <h1>Register</h1>
    <form>
      <div>
        <label for="username">Username</label>
        <input type="text" id="username" v-model="username" required>
      </div>


      <div>
        <label for="firstname">First Name</label>
        <input type="text" id="first_name" v-model="first_name" required>
      </div>


      <div>
        <label for="username">Last Name</label>
        <input type="text" id="last_name" v-model="last_name" required>
      </div>


      <div>
        <label for="email">Email</label>
        <input type="email" id="email" v-model="email" required>
      </div>
      <div>
        <label for="password">Password</label>
        <input type="password" id="password" v-model="password" required>
      </div>
      <div>
        <label for="school">School</label>
        <input type="text" id="school" v-model="school" required>
      </div>
      <div>
        <label for="gender">Gender</label>
        <select id="gender" v-model="gender" required>
          <option value="">Please select</option>
          <option value="male">Male</option>
          <option value="female">Female</option>
        </select>
      </div>
      <div>
        <button type="submit" @click.prevent="register">Register</button>
      </div>
    </form>
  </div>
</template>

<script>
import axios from 'axios';

export default {
  data() {
    return {
      username: '',
      email: '',
      password: '',
      school: '',
      gender: '',
      first_name: '',
      last_name: ''
    }
  },
  methods: {
    register() {
      axios.post('http://localhost:8000/api/register/', {
        username: this.username,
        email: this.email,
        password: this.password,
        school: this.school,
        gender: this.gender,
        first_name: this.first_name,
        last_name: this.last_name
      })
      .then(response => {
        console.log(response.data);
        alert('Registration successful');
      })
      .catch(error => {
        console.log(error);
        alert('Registration failed');
      });
    }
  }
}
</script>


 -->


 <template>
  <div class="registration-form">
    <h1>Register</h1>
    <form>
      <div class="form-group">
        <label for="username">Username</label>
        <input type="text" id="username" v-model="username" required>
      </div>

      <div class="form-group">
        <label for="firstname">First Name</label>
        <input type="text" id="first_name" v-model="first_name" required>
      </div>

      <div class="form-group">
        <label for="username">Last Name</label>
        <input type="text" id="last_name" v-model="last_name" required>
      </div>

      <div class="form-group">
        <label for="email">Email</label>
        <input type="email" id="email" v-model="email" required>
      </div>

      <div class="form-group">
        <label for="password">Password</label>
        <input type="password" id="password" v-model="password" required>
      </div>

      <div class="form-group">
        <label for="school">School</label>
        <input type="text" id="school" v-model="school" required>
      </div>

      <div class="form-group">
        <label for="gender">Gender</label>
        <select id="gender" v-model="gender" required>
          <option value="">Please select</option>
          <option value="male">Male</option>
          <option value="female">Female</option>
        </select>
      </div>

      <div class="form-group">
        <button type="submit" @click.prevent="register">Register</button>
      </div>
    </form>
  </div>
</template>


<script>
import axios from 'axios';

export default {
  data() {
    return {
      username: '',
      email: '',
      password: '',
      school: '',
      gender: '',
      first_name: '',
      last_name: ''
    }
  },
  methods: {
    register() {
      axios.post('http://localhost:8000/api/register/', {
        username: this.username,
        email: this.email,
        password: this.password,
        school: this.school,
        gender: this.gender,
        first_name: this.first_name,
        last_name: this.last_name
      })
      .then(response => {
        console.log(response.data);
        alert('Registration successful');
      })
      .catch(error => {
        console.log(error);
        alert('Registration failed');
      });
    }
  }
}
</script>


<style scoped>
  .registration-form {
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
    display: block;
    margin-bottom: 8px;
  }

  input[type=text],
  input[type=password],
  input[type=email],
  select {
    width: 100%;
    padding: 10px;
    margin-bottom: 20px;
    border: 1px solid #ccc;
    border-radius: 5px;
    box-sizing: border-box;
    font-size: 16px;
  }

  button[type=submit] {
    background-color: #4CAF50;
    color: white;
    padding: 12px 20px;
    border: none;
    border-radius: 5px;
    cursor: pointer;
    font-size: 16px;
  }

  button[type=submit]:hover {
    background-color: #45a049;
  }
</style>

