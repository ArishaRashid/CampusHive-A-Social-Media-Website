
    <template>
            <nav>
      <div class="logo">
        <img src= "https://static.vecteezy.com/system/resources/thumbnails/004/638/227/small/gold-color-beehive-honeycomb-logo-design-vector.jpg" alt="Italian Trulli">
      </div>
      <ul class="nav-links">
    <li @click="navigateTo('/home')"><a href="#">Home</a></li>
  <li @click="navigateTo('/homereview')"><a href="#">Reviews</a></li>
  <li @click="navigateTo('/homeresources')"><a href="#">Resources</a></li>
  <li @click="navigateTo('/EventHomePage')"><a href="#">Events</a></li>
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
      <div class="teacher-reviews-container">
        <h2>Teacher Reviews</h2>
        <div class="teacher-reviews-buttons">
          <button class="view-reviews-button" @click="viewReview">View Reviews</button>
          <button class="add-review-button" @click="addReview">Add Review</button>
        </div>
        <div v-if="currentModule === 'view-review'" class="module-container">
          <ViewReviews />
        </div>
        <div v-else-if="currentModule === 'add-review'" class="module-container">
          <AddReview />
        </div>
      </div>
    </template>
    
    <script>
    import ViewReviews from './ReviewsView.vue'
    import AddReview from './ReviewUpload.vue'
    
    export default {
      name: 'TeacherReviews',
      components: {
        ViewReviews,
        AddReview
      },
      data() {
        return {
          currentModule: ''
        }
      },
      methods: {
        viewReview() {
          this.$router.push('/viewreview')
          this.currentModule = 'view-review'
        },
        addReview() {
          this.$router.push('/addreview')
          this.currentModule = 'add-review'
        },
        navigateTo(route) {
        this.$router.push(route)
      }
      }
    }
    </script>
    
    <style scoped>
    .teacher-reviews-container {
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
    
    .teacher-reviews-buttons {
      display: flex;
      justify-content: center;
      gap: 2rem;
      margin-bottom: 2rem;
    }
    
    .view-reviews-button,
    .add-review-button {
      padding: 1rem 2rem;
      font-size: 1rem;
      font-weight: bold;
      color: #fff;
      background-color: #FFB347;
      border: none;
      border-radius: 0.5rem;
      cursor: pointer;
    }
    
    .module-container {
      display: flex;
      justify-content: center;
      margin-top: 2rem;
    }
    </style>
    