<!-- <template>
    <div>
      <h2>Add Resource</h2>
      <form @submit.prevent="submitForm">
        <div>
          <label>Name</label>
          <input v-model="name" type="text" required />
        </div>
        <div>
          <label>Category</label>
          <select v-model="category" required>
            <option value="">--Select--</option>
            <option value="assignment">Assignment</option>
            <option value="quiz">Quiz</option>
            <option value="notes">Notes</option>
            <option value="lecture-slides">Lecture Slides</option>
            <option value="class-activity">Class Activity</option>
            <option value="other">Other</option>
          </select>
        </div>
        <div>
          <label>Course Name</label>
          <input v-model="courseName" type="text" required />
        </div>
        <div>
          <label>Teacher Name</label>
          <input v-model="teacherName" type="text" required />
        </div>
        <div>
          <label>Semester</label>
          <input v-model="semester" type="text" required />
        </div>
        <div>
          <label>Resource</label>
          <input ref="fileInput" type="file" accept=".pdf,.txt,.jpg,.jpeg,.png,.doc,.docx" required />
        </div>
        <button type="submit">Submit</button>
      </form>
      <button @click="goBack">Return to Resources</button>
    </div>
  </template>
  



<script>
const axios = require('axios');
const FormData = require('form-data');

export default {
  data() {
    return {
      name: '',
      category: '',
      courseName: '',
      teacherName: '',
      semester: '',
      file: null
    }
  },
  methods: {
    async submitForm() {
      const data = new FormData();
      data.append('name', this.name);
      data.append('category', this.category);
      data.append('course', this.courseName);
      data.append('teacher', this.teacherName);
      data.append('semester', this.semester);
      data.append('file', this.file, this.file.name);

      const config = {
        method: 'post',
        url: 'http://localhost:8000/resources/upload/',
        headers: {
          //'Cookie': 'jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpZCI6NCwiZXhwIjoxNjg0MDEwMTQwLCJpYXQiOjE2ODQwMDY1NDB9.lN8lMiNJ8UhPZ0diL6hg5wxBXLmaPLvmsyglqEqqyKQ; messages=W1siX19qc29uX21lc3NhZ2UiLDAsMjUsIlJldmlldyBzdWJtaXR0ZWQgc3VjY2Vzc2Z1bGx5LiIsIiJdXQ:1pxv1s:0w1mZu2-JAMrfvH3jX4yOoOTSQDdo8q07e-ZrOl9cbA',
          //...data.getHeaders()
        },
        data: data
      };

      try {
        const response = await axios.request(config);
        console.log(JSON.stringify(response.data));
        // handle successful response
      } catch (error) {
        console.log(error);
        // handle error
      }
    },
    goBack() {
      // navigate back to resources page
      this.$router.push('/resources');
    }
  },
  mounted() {
    this.$refs.fileInput.addEventListener('change', () => {
      this.file = this.$refs.fileInput.files[0];
    });
  }
};
</script>
   -->

<!-- 
   <template>
    <div class="add-resource-container">
      <h2>Add Resource</h2>
      <form class="add-resource-form" @submit.prevent="submitForm">
        <div class="form-group">
          <label for="name">Name</label>
          <input type="text" id="name" v-model="name" required />
        </div>
        <div class="form-group">
          <label for="category">Category</label>
          <select id="category" v-model="category" required>
            <option value="">--Select--</option>
            <option value="assignment">Assignment</option>
            <option value="quiz">Quiz</option>
            <option value="notes">Notes</option>
            <option value="lecture-slides">Lecture Slides</option>
            <option value="class-activity">Class Activity</option>
            <option value="other">Other</option>
          </select>
        </div>
        <div class="form-group">
          <label for="courseName">Course Name</label>
          <input type="text" id="courseName" v-model="courseName" required />
        </div>
        <div class="form-group">
          <label for="teacherName">Teacher Name</label>
          <input type="text" id="teacherName" v-model="teacherName" required />
        </div>
        <div class="form-group">
          <label for="semester">Semester</label>
          <input type="text" id="semester" v-model="semester" required />
        </div>
        <div class="form-group">
          <label for="resource">Resource</label>
          <input type="file" id="resource" ref="fileInput" accept=".pdf,.txt,.jpg,.jpeg,.png,.doc,.docx" required />
        </div>
        <button class="submit-button" type="submit">Submit</button>
      </form>
      <button class="return-resources-button" @click="goBack">Return to Resources</button>
    </div>
  </template>
  
  <script>
  import axios from 'axios';
  
  export default {
    data() {
      return {
        name: '',
        category: '',
        courseName: '',
        teacherName: '',
        semester: '',
        file: null
      };
    },
    methods: {
      async submitForm() {
        const data = new FormData();
        data.append('name', this.name);
        data.append('category', this.category);
        data.append('course', this.courseName);
        data.append('teacher', this.teacherName);
        data.append('semester', this.semester);
        data.append('file', this.file, this.file.name);
  
        const config = {
          method: 'post',
          url: 'http://localhost:8000/resources/upload/',
          headers: {
            //'Cookie': 'jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpZCI6NCwiZXhwIjoxNjg0MDEwMTQwLCJpYXQiOjE2ODQwMDY1NDB9.lN8lMiNJ8UhPZ0diL6hg5wxBXLmaPLvmsyglqEqqyKQ; messages=W1siX19qc29uX21lc3NhZ2UiLDAsMjUsIlJldmlldyBzdWJtaXR0ZWQgc3VjY2Vzc2Z1bGx5LiIsIiJdXQ:1pxv1s:0w1mZu2-JAMrfvH3jX4yOoOTSQDdo8q07e-ZrOl9cbA',
            //...data.getHeaders()
          },
          data: data
        };
  
        try {
          const response = await axios.request(config);
          console.log(JSON.stringify(response.data));
          // handle successful response
        } catch (error) {
          console.log(error);
          // handle error
        }
      },
      goBack() {
        // navigate back to resources page
        this.$router.push('/resources');
      }
    },
    mounted() {
      this.$refs.fileInput.addEventListener('change', () => {
        this.file = this.$refs.fileInput.files[0];
      });
    }
  };
  </script>
  
  <style scoped>
  .add-resource-container {
    max-width: 600px;
    margin: 0 auto;
    padding: 2rem;
    background-color: #fff;
    box-shadow: 0 2px 4px rgba(0, 0, 0, 0.1);
  }
  
  h2 {
    font-size: 1.5rem;
    color: #FFB347;
    margin-bottom: 2rem;
  }
  
  .add-resource-form {
    display: grid;
    gap: 1.5rem;
  }
  
  .form-group {
    display: grid;
    gap: 0.5rem;
  }
  
  label {
    font-size: 1rem;
    color: #FFB347;
  }
  
  input[type="text"],
  select,
  input[type="file"] {
    padding: 0.5rem;
    font-size: 1rem;
    border: 1px solid #ccc;
    border-radius: 0.25rem;
  }
  
  button {
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
  
  </style>
   -->
   <template>
    <div class="add-resource-container">
      <h2>Add Resource</h2>
      <div v-if="errorMessage" class="error-message">{{ errorMessage }}</div>
  
      <form class="add-resource-form" @submit.prevent="submitForm">
        <div class="form-group" :class="{ 'has-error': invalidCourse }">
          <label for="name">Name</label>
          <input type="text" id="name" v-model="name" required />
        </div>
        <div class="form-group" :class="{ 'has-error': invalidCourse }">
          <label for="category">Category</label>
          <select id="category" v-model="category" required>
            <option value="">--Select--</option>
            <option value="assignment">Assignment</option>
            <option value="quiz">Quiz</option>
            <option value="notes">Notes</option>
            <option value="lecture-slides">Lecture Slides</option>
            <option value="class-activity">Class Activity</option>
            <option value="other">Other</option>
          </select>
        </div>
        <div class="form-group" :class="{ 'has-error': invalidCourse }">
          <label for="courseName">Course Name</label>
          <input type="text" id="courseName" v-model="courseName" required />
        </div>
        <div class="form-group" :class="{ 'has-error': invalidTeacher }">
          <label for="teacherName">Teacher Name</label>
          <input type="text" id="teacherName" v-model="teacherName" required />
        </div>
        <div class="form-group">
          <label for="semester">Semester</label>
          <input type="text" id="semester" v-model="semester" required />
        </div>
        <div class="form-group">
          <label for="resource">Resource</label>
          <input type="file" id="resource" ref="fileInput" accept=".pdf,.txt,.jpg,.jpeg,.png,.doc,.docx" required />
        </div>
        <button class="submit-button" type="submit">Submit</button>
      </form>
      <button class="return-resources-button" @click="goBack">Return to Resources</button>
    </div>
  </template>
  
  <script>
  import axios from 'axios';
  
  export default {
    data() {
      return {
        name: '',
        category: '',
        courseName: '',
        teacherName: '',
        semester: '',
        file: null,
        errorMessage: '',
        invalidCourse: false,
        invalidTeacher: false
      };
    },
    methods: {
      async submitForm() {
        this.invalidCourse = false;
        this.invalidTeacher = false;
  
        const data = new FormData();
        data.append('name', this.name);
        data.append('category', this.category);
        data.append('course', this.courseName);
        data.append('teacher', this.teacherName);
        data.append('semester', this.semester);
        data.append('file', this.file, this.file.name);
  
        const config = {
          method: 'post',
          url: 'http://localhost:8000/resources/upload/',
          headers: {
            //'Cookie': 'jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpZCI6NCwiZXhwIjoxNjg0MDEwMTQwLCJpYXQiOjE2ODQwMDY1NDB9.lN8lMiNJ8UhPZ0diL6hg5wxBXLmaPLvmsyglqEqqyKQ; messages=W1siX19qc29uX21lc3NhZ2UiLDAsMjUsIlJldmlldyBzdWJtaXR0ZWQgc3VjY2Vzc2Z1bGx5LiIsIiJdXQ:1pxv1s:0w1mZu2-JAMrfvH3jX4yOoOTSQDdo8q07e-ZrOl9cbA',
            //...data.getHeaders()
          },
          data: data
        };
  
        try {
          const response = await axios.request(config);
          console.log(JSON.stringify(response.data));
          // handle successful response
        } catch (error) {
          console.log(error);
          if (error.response.status === 400) {
            if (error.response.data.courseError) {
              this.invalidCourse = true;
              this.errorMessage = error.response.data.courseError;
            }
            if (error.response.data.teacherError) {
              this.invalidTeacher = true;
              this.errorMessage = error.response.data.teacherError;
            }
          } else {
            this.errorMessage = error.response.data;
          }
  
          // Scroll to the top of the page to show the error message
          window.scrollTo(0, 0);
        }
      },
      goBack() {
        // navigate back to resources page
        this.$router.push('/homeresources');
      }
    },
    mounted() {
      this.$refs.fileInput.addEventListener('change', () => {
        this.file = this.$refs.fileInput.files[0];
      });
    }
  };
  </script>
  
  <style scoped>
  .add-resource-container {
    max-width: 600px;
    margin: 0 auto;
    padding: 2rem;
    background-color: #fff;
    box-shadow: 0 2px 4px rgba(0, 0, 0, 0.1);
  }
  
  h2 {
    font-size: 1.5rem;
    color: #FFB347;
    margin-bottom: 2rem;
  }
  
  .add-resource-form {
    display: grid;
    gap: 1.5rem;
  }
  
  .form-group {
    display: grid;
    gap: 0.5rem;
  }
  
  label {
    font-size: 1rem;
    color: #FFB347;
  }
  
  input[type="text"],
  select,
  input[type="file"] {
    padding: 0.5rem;
    font-size: 1rem;
    border: 1px solid #ccc;
    border-radius: 0.25rem;
  }
  
  button {
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
  
  .error-message {
    margin-bottom: 1rem;
    color: red;
  }
  
  .has-error input[type="text"],
  .has-error select {
    border-color: red;
  }
  </style>