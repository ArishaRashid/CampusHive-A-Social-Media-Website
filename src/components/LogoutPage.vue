<template>
  <div class="logout-page">
    <p>Are you sure you want to sign out?</p>
    <button @click="logoutUser">Logout</button>
  </div>
</template>

<script>
import axios from 'axios'

export default {
  methods: {
    async logoutUser() {
      try {
        await axios.post('http://localhost:8000/api/logout/')
        this.$router.push('/login')
      } catch (err) {
        console.error(err)
      }
    }
  }
}
</script>

<style scoped>
.logout-page {
  display: flex;
  flex-direction: column;
  align-items: center;
  justify-content: center;
  height: 100vh;
}

p {
  font-size: 24px;
  margin-bottom: 20px;
}

button {
  padding: 12px 24px;
  background-color: #2c3e50;
  color: white;
  border: none;
  border-radius: 4px;
  font-size: 18px;
  cursor: pointer;
}

button:hover {
  background-color: #34495e;
}
</style>
