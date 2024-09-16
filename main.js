const { app, BrowserWindow } = require('electron');
const path = require('path');

async function createWindow () {
  const mainWindow = new BrowserWindow({
    width: 800,
    height: 600,
    webPreferences: {
      preload: path.join(__dirname, 'preload.js'),
      nodeIntegration: true,
      contextIsolation: false,
    }
  });

  // Dynamically import 'electron-is-dev'
  const isDev = await import('electron-is-dev');

  const startURL = isDev.default
    ? 'http://localhost:3000'
    : `file://${path.join(__dirname, 'dist', 'index.html')}`;

  mainWindow.loadURL(startURL);
}

app.whenReady().then(() => {
  createWindow();
});

app.on('window-all-closed', () => {
  if (process.platform !== 'darwin') app.quit();
});
