import boto3

def connect_to_aws(region_name, aws_access_key_id, aws_secret_access_key):
    try:
        # Create a session using provided AWS credentials
        session = boto3.Session(
            aws_access_key_id=aws_access_key_id,
            aws_secret_access_key=aws_secret_access_key,
            region_name=region_name
        )

        # Create an EC2 client using the session
        ec2_client = session.client('ec2')

        # Example: List all EC2 instances in the region
        response = ec2_client.describe_instances()
        instances = response['Reservations']

        # Print information about each instance
        for reservation in instances:
            for instance in reservation['Instances']:
                print(f"Instance ID: {instance['InstanceId']}")
                print(f"Public IP: {instance.get('PublicIpAddress', 'N/A')}")
                print(f"Private IP: {instance.get('PrivateIpAddress', 'N/A')}")
                print()

        print("Connected to AWS successfully.")
    except Exception as e:
        print(f"Error connecting to AWS: {e}")

# Example usage
if __name__ == "__main__":
    # Replace these values with your AWS credentials and configuration
    aws_region = 'your_aws_region'
    aws_access_key_id = 'your_access_key_id'
    aws_secret_access_key = 'your_secret_access_key'

    # Call the function to connect to AWS
    connect_to_aws(aws_region, aws_access_key_id, aws_secret_access_key)
