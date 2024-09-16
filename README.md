# Desktop Application 



# Navigate to your project directory
mkdir -p project-root/{public/{assets},src/{components/{Home,DataConfiguration,GraphManager,Widgets,Common},state,services,utils},main,styles,tests/{component-tests,integration-tests}}

# Create files in the respective directories
touch project-root/public/index.html
touch project-root/src/components/Home/{Home.js,Home.css}
touch project-root/src/components/DataConfiguration/{DataConfigForm.js,DataConfigForm.css}
touch project-root/src/components/GraphManager/{GraphList.js,GraphEditor.js,GraphWidget.js}
touch project-root/src/components/Widgets/{WidgetManager.js,Widget.css}
touch project-root/src/components/Common/.gitkeep  # Placeholder file
touch project-root/src/state/{store.js,actions.js}
touch project-root/src/services/{ipcService.js,dataService.js,graphService.js}
touch project-root/src/utils/{validation.js,constants.js,helpers.js}
touch project-root/main/{main.js,preload.js,menu.js}
touch project-root/styles/{global.css,theme.css}
touch project-root/tests/utils.js

# Create additional root-level files
touch project-root/{electron.js,package.json,README.md,.gitignore}




mkdir -p: Creates the necessary folder structure, including nested directories.
touch: Creates the files in their respective directories.
.gitkeep: Creates an empty placeholder file in the Common folder to ensure the directory is tracked by Git, as Git ignores empty directories by default.