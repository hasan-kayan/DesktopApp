const THREE = require("three");
require("three/examples/js/controls/OrbitControls");
require("three/examples/js/loaders/OBJLoader");
require("three/examples/js/grid-helper");

let scene, camera, renderer, controls;

function init() {
  console.log("Hello from renderer.js");
  scene = new THREE.Scene();
  scene.background = new THREE.Color(0x121212); // Match background color

  camera = new THREE.PerspectiveCamera(
    75,
    window.innerWidth / window.innerHeight,
    0.1,
    1000
  );
  camera.position.z = 5;

  renderer = new THREE.WebGLRenderer({ antialias: true });
  renderer.setSize(window.innerWidth, window.innerHeight);
  document.body.appendChild(renderer.domElement);

  controls = new THREE.OrbitControls(camera, renderer.domElement);

  const ambientLight = new THREE.AmbientLight(0xcccccc, 0.4);
  scene.add(ambientLight);

  const directionalLight = new THREE.DirectionalLight(0xffffff, 0.8);
  directionalLight.position.set(1, 1, 0).normalize();
  scene.add(directionalLight);

  const objLoader = new THREE.OBJLoader();
  objLoader.load("model/satellite_obj.obj", (object) => {
    scene.add(object);
  });
  const gridHelper = new THREE.GridHelper(10, 10);
  scene.add(gridHelper);

  window.addEventListener("resize", onWindowResize, false);

  animate();
}

function onWindowResize() {
  camera.aspect = window.innerWidth / window.innerHeight;
  camera.updateProjectionMatrix();
  renderer.setSize(window.innerWidth, window.innerHeight);
}

function animate() {
  requestAnimationFrame(animate);
  controls.update();
  renderer.render(scene, camera);
}

init();
