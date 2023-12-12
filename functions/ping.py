import subprocess

def ping_ip(target_ip):
    """
    Sends a ping to the target IP address and returns True if the target is reachable, False otherwise.
    """
    try:
        subprocess.check_output(["ping", "-c", "1", target_ip], stderr=subprocess.STDOUT, text=True)
        return True
    except subprocess.CalledProcessError:
        return False
