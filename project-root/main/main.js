const { app, BrowserWindow, ipcMain } = require('electron');
const path = require('path');
const { list } = require('@serialport/list');

let mainWindow;

function createWindow() {
  mainWindow = new BrowserWindow({
    width: 800,
    height: 600,
    webPreferences: {
      preload: path.join(__dirname, 'preload.js'),
      nodeIntegration: false,
      contextIsolation: true,  // To secure IPC
      enableRemoteModule: false,
      sandbox: false,
    },
  });

  mainWindow.loadFile(path.join(__dirname, '../public/index.html'));

  mainWindow.on('closed', function () {
    mainWindow = null;
  });
}

// Handle IPC request from renderer for port list
ipcMain.handle('get-ports', async () => {
  try {
    const ports = await list();  // Fetch the list of ports
    return ports;
  } catch (error) {
    return { error: error.message };
  }
});

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
