
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
      <div class="resources-container">
        <h2>Resources</h2>
        <div class="resources-buttons">
          <button class="view-resources-button" @click="viewResources">View Resources</button>
          <button class="add-resource-button" @click="addResource">Add Resource</button>
        </div>
        <div v-if="currentModule === 'view-resources'" class="module-container">
          <ViewResources />
        </div>
        <div v-else-if="currentModule === 'add-resource'" class="module-container">
          <AddResource />
        </div>
      </div>
    </template>
    
    <script>
    import ViewResources from './ResourcesView.vue'
    import AddResource from './ResourceUpload.vue'
    
    
    export default {
      name: 'ResourcesModule',
      components: {
        ViewResources,
        AddResource
      },
      data() {
        return {
          currentModule: ''
        }
      },
      methods: {
        viewResources() {
          this.$router.push('/viewresource')
          this.currentModule = 'view-resources'
        },
        addResource() {
          this.$router.push('/addresource')
          this.currentModule = 'add-resource'
        },
        navigateTo(route) {
        this.$router.push(route)
      }
      }
    }
    </script>
    
    <style scoped>
    .resources-container {
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
    
    .resources-buttons {
      display: flex;
      justify-content: center;
      gap: 2rem;
      margin-bottom: 2rem;
    }
    
    .view-resources-button,
    .add-resource-button {
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
    