<template>
  <div class="view-resources-container">
    <h2>View Resources</h2>
    <form class="view-resources-form" @submit.prevent="getResources">
      <div class="form-group">
        <label for="courseName">Course Name:</label>
        <input type="text" id="courseName" v-model="courseName" required>
      </div>
      <div class="form-group">
        <label for="teacherName">Teacher Name:</label>
        <input type="text" id="teacherName" v-model="teacherName" required>
      </div>
      <button class="get-resources-button" type="submit">Get Resources</button>
    </form>
    <button class="return-resources-button" @click="goBack">Return to Resources</button>

    <div v-if="tableHtml" class="resources-table">
      <h3>Available Resources</h3>
      <div v-html="tableHtml"></div>
    </div>
    <div v-else>
      <p>No resources available</p>
    </div>
  </div>
</template>

<script>
import axios from 'axios';

export default {
  data() {
    return {
      courseName: '',
      teacherName: '',
      resources: [],
      tableHtml: '',
      errorMessage: ''
    };
  },
  methods: {
    async getResources() {
      let data = new URLSearchParams();
      data.append('teacher', this.teacherName);
      data.append('course', this.courseName);

      let config = {
        method: 'get',
        maxBodyLength: Infinity,
        url: 'http://localhost:8000/resources/view',
        headers: {
          'Content-Type': 'application/x-www-form-urlencoded',
        },
        params: {
          teacher: this.teacherName,
          course: this.courseName
        },
        data: data
      };

      try {
        const response = await axios.request(config);
        this.resources = response.data;

        // Build the table HTML content
        let tableHtml = '<table>';
        tableHtml += '<thead><tr><th>Course</th><th>Teacher</th><th>Semester</th><th>Student Name</th><th>Resource Link</th></tr></thead>';
        tableHtml += '<tbody>';
        for (let i = 0; i < this.resources.length; i++) {
          const resource = this.resources[i];
          const [course, teacher, semester, studentName, link] = resource.split(',');

          tableHtml += `<tr>`;
          tableHtml += `<td>${course}</td>`;
          tableHtml += `<td>${teacher}</td>`;
          tableHtml += `<td>${semester}</td>`;
          tableHtml += `<td>${studentName}</td>`;
          tableHtml += `<td><a href="${link}" target="_blank">Resource Link</a></td>`;
          tableHtml += `</tr>`;
        }
        tableHtml += '</tbody></table>';
        this.tableHtml = tableHtml;
        this.tableHtml = this.resources.table_html;
        this.errorMessage = ''; // Clear any previous error messages
} catch (error) {
  alert(error);
  this.tableHtml = '';
  
}
    },
    goBack() {
      this.$router.push('/homeresources');
    }
  }
};
</script>

<style scoped>
.view-resources-container {
  display: flex;
  flex-direction: column;
  align-items: center;
}

h2 {
  font-size: 2.5rem;
  font-weight: bold;
  margin: 2rem 0;
  color: #FFE066;
}

.view-resources-form {
  display: flex;
  flex-direction: column;
  gap: 1rem;
  margin-bottom: 2rem;
}

.form-group {
  display: flex;
  flex-direction: column;
}

label {
  font-size: 1rem;
  color: #FFB347;
  margin-bottom: 0.5rem;
}

input[type="text"] {
  padding: 0.5rem;
  font-size: 1rem;
  border: 1px solid #ccc;
  border-radius: 0.25rem;
}

.get-resources-button,
.return-resources-button {
  padding: 0.75rem 1.5rem;
  font-size: 1rem;
  font-weight: bold;
  color: #fff;
  background-color: #FFB347;
  border: none;
  border-radius: 0.5rem;
  cursor: pointer;
}

.return-resources-button {
  margin-top: 1rem;
}

.resources-table {
  margin-top: 2rem;
}

table {
  width: 100%;
  border-collapse: collapse;
}

th {
  font-weight: bold;
  text-align: left;
  background-color: #FFB347;
  color: #fff;
  padding: 0.5rem;
}

td {
  padding: 0.5rem;
  border: 1px solid #ccc;
}

</style>
