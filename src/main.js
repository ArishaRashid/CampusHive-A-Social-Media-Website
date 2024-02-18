import { createApp } from 'vue';
import App from './App.vue';
import RegistrationForm from './components/RegistrationForm.vue';
import HelloWorld from './components/HelloWorld.vue';
import Tester from './components/TesterPage.vue';
import Login from './components/LoginPage.vue';
import Logout from './components/LogoutPage.vue';
import Home from './components/HomePage.vue';



//REVIEWS
import ReviewHome from './components/TeacherReviews.vue'
import AddReview from './components/ReviewUpload.vue'
import ViewReview from './components/ReviewsView.vue';



//RESOURCES
import ResourcesHome from './components/ResourcesModule.vue'
import AddResource from './components/ResourceUpload.vue'
import ViewResource from './components/ResourcesView.vue';



// //EVENTS
import EventHomePage from './components/EventHomePage.vue';
import ViewMyEvents from './components/ViewMyEvents.vue';
import updateEvent from './components/updateEvent.vue';
import AddEvent from './components/AddEvent.vue';









import { createRouter, createWebHistory } from 'vue-router';

const router = createRouter({
  history: createWebHistory(),
  routes: [
    {
      path: '/register',
      component: RegistrationForm,
    },
    {
        path: '/',
        component: HelloWorld,
    },
    {
        path: '/test',
        component: Tester,
    },
    {
      path: '/login',
      component: Login,
  },
  {
    path: '/home',
    component: Home,
},
{
  path: '/logout',
  component: Logout,
},


//REVIEWS
{
  path: '/homereview',
  component: ReviewHome,
},
{
  path: '/addreview',
  component: AddReview,
},
{
  path: '/viewreview',
  component: ViewReview,
},


//REVIEWS
{
  path: '/homeresources',
  component: ResourcesHome,
},
{
  path: '/addresource',
  component: AddResource,
},
{
  path: '/viewresource',
  component: ViewResource,
},


//EVENTS
{
  path: '/EventHomePage',
  component: EventHomePage,
},
{
  path: '/ViewMyEvents',
  component: ViewMyEvents,
},
{
  path: '/updateEvent',
  component: updateEvent,
},
{
  path: '/AddEvent',
  component: AddEvent,
},




  ],
});

const app = createApp(App);
app.use(router);
app.mount('#app');
