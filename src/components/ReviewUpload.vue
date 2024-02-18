


<template>
  <div class="add-review-container">
    <h2>Add Review</h2>
    <form class="add-review-form" @submit.prevent="submitForm">
      <div class="form-group">
        <label for="teacher">Teacher Name:</label>
        <input type="text" id="teacher" v-model="teacher" required>
      </div>
      <div class="form-group">
        <label for="course">Course Name:</label>
        <input type="text" id="course" v-model="course" required>
      </div>
      <div class="form-group">
        <label for="category1rating">Teacher Rating:</label>
        <input type="number" id="category1rating" v-model="rating1" min="0" max="10" required>
      </div>
      <div class="form-group">
        <label for="category2rating">Skills</label>
        <input type="number" id="category2rating" v-model="rating2" min="0" max="10" required>
      </div>
      <div class="form-group">
        <label for="category3rating">Grading</label>
        <input type="number" id="category3rating" v-model="rating3" min="0" max="10" required>
      </div>
      <div class="form-group">
        <label for="category4rating">Interactive Lessons</label>
        <input type="number" id="category4rating" v-model="rating4" min="0" max="10" required>
      </div>
      <div class="form-group">
        <label for="overall_rating">Attendance</label>
        <input type="number" id="overall_rating" v-model="overall_rating" min="1" max="5" required>
      </div>
      <div class="form-group">
        <label for="review_text">Additional Comments</label>
        <textarea id="review_text" v-model="review_text" required></textarea>
      </div>
      <button class="submit-review-button" type="submit">Submit Review</button>
    </form>
    <button class="return-reviews-button" @click="goBack">Return to Reviews</button>
  </div>
</template>

<script>
import axios from 'axios';
import qs from 'qs';

export default {
  data() {
    return {
      teacher: '',
      course: '',
      rating1: '',
      rating2: '',
      rating3: '',
      rating4: '',
      overall_rating: '',
      review_text: ''
    };
  },
  methods: {
    submitForm() {
      let data = qs.stringify({
        teacher: this.teacher,
        course: this.course,
        rating1: this.rating1,
        rating2: this.rating2,
        rating3: this.rating3,
        rating4: this.rating4,
        overall_rating: this.overall_rating,
        review_text: this.review_text 
      });

      let config = {
        method: 'post',
        maxBodyLength: Infinity,
        url: 'http://localhost:8000/teacherreview/index/leave_review/',
        headers: { 
          'Content-Type': 'application/x-www-form-urlencoded'
        },
        data: data
      };

      axios.request(config)
        .then((response) => {
          console.log(JSON.stringify(response.data));
        })
        .catch((error) => {
          console.log(error);
        });
    },
    goBack() {
      this.$router.push('/homereview');
    }
  }
}
</script>

<style scoped>
.add-review-container {
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

.add-review-form {
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

input[type="text"],
input[type="number"],
textarea {
  padding: 0.5rem;
  font-size: 1rem;
  border: 1px solid #ccc;
  border-radius: 0.25rem;
}

.submit-review-button,
.return-reviews-button {
  padding: 0.75rem 1.5rem;
  font-size: 1rem;
  font-weight: bold;
  color: #fff;
  background-color: #FFB347;
  border: none;
  border-radius: 0.5rem;
  cursor: pointer;
}

.return-reviews-button {
  margin-top: 1rem;
}

</style>
