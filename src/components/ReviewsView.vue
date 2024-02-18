
<template>
  <div class="view-reviews-container">
    <h2>View Reviews</h2>
    <form class="reviews-form" @submit.prevent="getReviews">
      <div class="form-group">
        <label for="courseName">Course Name:</label>
        <input id="courseName" v-model="courseName" required>
      </div>
      <div class="form-group">
        <label for="teacherName">Teacher Name:</label>
        <input id="teacherName" v-model="teacherName" required>
      </div>
      <button class="get-reviews-button" type="submit">Get Reviews</button>
    </form>
    <button class="return-reviews-button" @click="goBack">Return to Reviews</button>

    <div v-if="tableHtml" class="reviews-table">
      <h3>Available Reviews</h3>
      <div v-html="tableHtml"></div>
    </div>
    <div v-else class="no-reviews-message">
      <p>No reviews available</p>
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
      reviews: [],
      tableHtml: '',
    };
  },
  methods: {
    async getReviews() {
      let data = new URLSearchParams();
      data.append('course_name', this.courseName);
      data.append('teacher_name', this.teacherName);

      let config = {
        method: 'get',
        maxBodyLength: Infinity,
        url: 'http://localhost:8000/teacherreview/index/view_teacher_review',
        headers: {
          'Content-Type': 'application/x-www-form-urlencoded',
        },
        params: {
          teacher_name: this.teacherName,
          course_name: this.courseName,
        },
        data: data,
      };

      try {
        const response = await axios.request(config);
        this.reviews = response.data;
        console.log("These are reviews", this.reviews);

        // Build the table HTML content
        let tableHtml = '<table>';
        tableHtml +=
          '<thead><tr><th>Serial Number</th><th>Overall Rating</th><th>Rating 1</th><th>Rating 2</th><th>Rating 3</th><th>Rating 4</th><th>Review Text</th><th>Date Written</th><th>Student Name</th></tr></thead>';
        tableHtml += '<tbody>';
        for (let i = 0; i < this.reviews.length; i++) {
          const review = this.reviews[i];
          const [
            serialNumber,
            dateAdded,
            studentName,
            teacherRating,
            teachingSkills,
            grading,
            interactiveLessons,
            attendance,
            additionalComments,
          ] = review.split(',');

          tableHtml += '<tr>';
          tableHtml += `<td>${serialNumber}</td>`;
          tableHtml += `<td>${dateAdded}</td>`;
          tableHtml += `<td>${studentName}</td>`;
          tableHtml += `<td>${teacherRating}</td>`;
          tableHtml += `<td>${teachingSkills}</td>`;
          tableHtml += `<td>${grading}</td>`;
          tableHtml += `<td>${interactiveLessons}</td>`;
          tableHtml += `<td>${attendance}</td>`;
          tableHtml += `<td>${additionalComments}</td>`;
          tableHtml += '</tr>';
        }
        tableHtml += '</tbody></table>';
        this.tableHtml = tableHtml;
        this.tableHtml = this.reviews.table_html;
      } catch (error) {
        console.log(error);
      }
    },
    goBack() {
      this.$router.push('/homereview');
    },
  },
};
</script>

<style scoped>
.view-reviews-container {
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

.reviews-form {
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

input {
  padding: 0.5rem;
  font-size: 1rem;
  border: 1px solid #ccc;
  border-radius: 0.25rem;
}

.get-reviews-button,
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

.reviews-table {
  margin-top: 2rem;
}

table {
  width: 100%;
  border-collapse: collapse;
}

thead {
  background-color: #FFB347;
  color: #fff;
}

th, td {
  padding: 0.75rem;
  text-align: left;
  border-bottom: 1px solid #ccc;
}

.no-reviews-message {
  margin-top: 2rem;
  color: #fff;
}
</style>
