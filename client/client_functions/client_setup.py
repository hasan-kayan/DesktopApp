import os
import shutil
import platform

def setup_program():
    # Create a directory for data storage (replace 'data_directory' with your desired directory name)
    data_directory = "data_directory"
    if not os.path.exists(data_directory):
        os.makedirs(data_directory)
        print(f"Created directory: {data_directory}")
        # Perform any other setup tasks as needed for your program

    print("Setup complete.")
    
def declare_run_at_startup():
    # Get the platform (Windows or Linux)
    current_platform = platform.system()

    # Get the path to the script
    script_path = os.path.abspath(__file__)

    if current_platform == "Windows":
        # Add the script to the Windows Startup folder
        startup_folder = os.path.join(os.environ["APPDATA"], "Microsoft", "Windows", "Start Menu", "Programs", "Startup")
        shutil.copy(script_path, startup_folder)
        print(f"Script added to Windows Startup folder.")
    elif current_platform == "Linux":
        # Add a cron job to run the script at reboot on Linux
        os.system(f'(crontab -l ; echo "@reboot /usr/bin/python3 {script_path}") | crontab -')
        print(f"Script added to Linux crontab for running at reboot.")
    else:
        print("Unsupported platform. Cannot declare run at startup.")



if __name__ == "__main__":
    setup_program()

