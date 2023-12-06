import os
import shutil
import sys

def create_program_copies(target_directories):
    # Get the path to the current script
    script_path = os.path.abspath(sys.argv[0])

    # Ensure the script path is not empty
    if not script_path:
        print("Error: Unable to determine script path.")
        return

    # Iterate through each target directory and copy the script
    for target_directory in target_directories:
        # Ensure the target directory exists
        if not os.path.exists(target_directory):
            print(f"Error: Target directory '{target_directory}' does not exist.")
            continue

        # Construct the destination path for the copy
        script_filename = os.path.basename(script_path)
        destination_path = os.path.join(target_directory, script_filename)

        # Copy the script to the target directory
        try:
            shutil.copy(script_path, destination_path)
            print(f"Script copied to '{destination_path}'.")
        except Exception as e:
            print(f"Error copying script to '{destination_path}': {e}")

# Example usage
if __name__ == "__main__":
    # Specify the target directories where copies will be created
    target_directories = ["C:\\TargetDirectory1", "/path/to/TargetDirectory2"]

    # Call the function to create copies in the specified directories
    create_program_copies(target_directories)
