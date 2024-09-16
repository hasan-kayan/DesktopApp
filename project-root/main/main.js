const { app, BrowserWindow } = require('electron');
const path = require('path');

let mainWindow;

function createWindow() {
  mainWindow = new BrowserWindow({
    width: 800,
    height: 600,
    webPreferences: {
      preload: path.join(__dirname, 'preload.js'),
      nodeIntegration: false,  // Disable Node.js integration
      contextIsolation: true,  // Enable context isolation for security
      enableRemoteModule: false // Disable remote module for additional security
    },
    icon: path.join(__dirname, '../public/assets/logo.png') // Path to your custom icon
  });

  mainWindow.loadFile(path.join(__dirname, '../dist/index.html'));
  mainWindow.webContents.openDevTools();  // Open DevTools for debugging
}

app.on('ready', createWindow);

app.on('window-all-closed', function () {
  if (process.platform !== 'darwin') {
    app.quit();
  }
});

app.on('activate', function () {
  if (mainWindow === null) {
    createWindow();
  }
});
