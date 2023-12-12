import socket
import requests
from pysnmp.hlapi import *
from datetime import datetime

def vulnerability_scan(target_ip, target_port):
    vulnerabilities = []

    # Örnek bir HTTP zafiyet taraması
    if target_port == 80:
        url = f"http://{target_ip}:{target_port}/"
        try:
            response = requests.get(url)
            if "vulnerable" in response.text:
                vulnerabilities.append("HTTP server is vulnerable.")
        except requests.RequestException:
            pass

    # Örnek başka bir servis taraması
    # Bu kısımları, taramak istediğiniz özel servis ve zafiyetlere göre özelleştirebilirsiniz.

    return vulnerabilities

# Kullanım örneği:
# target_ip = "127.0.0.1"  # Hedef IP adresini değiştirin
# target_port = 80         # Hedef portu değiştirin

# vulnerabilities = vulnerability_scan(target_ip, target_port)

# if vulnerabilities:
#     print("Vulnerabilities found:")
#     for vulnerability in vulnerabilities:
#         print("- ", vulnerability)
# else:
#     print("No vulnerabilities found.")



def sql_injection_scan(target_url, parameter_name):
    vulnerabilities = []

    payloads = ["' OR '1'='1'", "'; DROP TABLE users; --", "UNION SELECT 1,2,3"]

    for payload in payloads:
        try:
            # Gönderilen payload ile HTTP isteği yapılır
            response = requests.get(target_url, params={parameter_name: payload})

            # Eğer payload'ın etkisiyle beklenen değişiklikler oluyorsa, zafiyet bulunmuş demektir.
            if payload in response.text:
                vulnerabilities.append(f"SQL Injection vulnerability found with payload: {payload}")

        except requests.RequestException:
            pass

    return vulnerabilities

# # Kullanım örneği:
# target_url = "http://example.com/login"  # Hedef URL'yi değiştirin
# parameter_name = "username"               # Test edilecek parametre adını değiştirin

# vulnerabilities = sql_injection_scan(target_url, parameter_name)

# if vulnerabilities:
#     print("Vulnerabilities found:")
#     for vulnerability in vulnerabilities:
#         print("- ", vulnerability)
# else:
#     print("No vulnerabilities found.")




def firewall_check(target_ip, target_port):
    try:
        sock = socket.create_connection((target_ip, target_port), timeout=2)
        sock.close()
        print(f"Connection to {target_ip}:{target_port} successful. Firewall is open.")
        return True
    except (socket.timeout, ConnectionRefusedError):
        print(f"Connection to {target_ip}:{target_port} failed. Firewall may be closed.")
        return False

# # Kullanım örneği:
# target_ip = "example.com"  # Hedef IP adresini veya alan adını değiştirin
# target_port = 80           # Hedef portu değiştirin

# firewall_check(target_ip, target_port)




def check_snmp_security(device_ip, snmp_community):
    errorIndication, errorStatus, errorIndex, varBinds = next(
        getCmd(SnmpEngine(),
               CommunityData(snmp_community),
               UdpTransportTarget((device_ip, 161)),
               ContextData(),
               ObjectType(ObjectIdentity('SNMPv2-MIB', 'sysDescr', 0)),
               ObjectType(ObjectIdentity('SNMPv2-MIB', 'sysContact', 0)),
               ObjectType(ObjectIdentity('SNMPv2-MIB', 'sysName', 0)))
    )

    if errorIndication:
        print(f"SNMP Error: {errorIndication}")
        return False
    elif errorStatus:
        print(f"SNMP Error: {errorStatus}")
        return False
    else:
        print("SNMP Security Policies:")
        for varBind in varBinds:
            print(f"{varBind[0]} = {varBind[1]}")
        return True

# # Kullanım örneği:
# device_ip = "192.168.1.1"  # Cihazın IP adresini değiştirin
# snmp_community = "public"  # SNMP topluluk adını değiştirin

# check_snmp_security(device_ip, snmp_community)

def ssl_check(url):
    try:
        response = requests.get(url, timeout=5, verify=True)
        
        # Sertifika bilgilerini al
        cert_info = response.connection.sock.getpeercert()

        # Sertifika son kullanma tarihini al
        expiration_date = datetime.strptime(cert_info['notAfter'], '%b %d %H:%M:%S %Y %Z')
        
        # Şu anki tarih ile karşılaştır
        if expiration_date > datetime.now():
            print("SSL/TLS Certificate is valid.")
            print(f"Expiration Date: {expiration_date}")
            return True
        else:
            print("SSL/TLS Certificate has expired.")
            print(f"Expiration Date: {expiration_date}")
            return False
    except requests.exceptions.RequestException as e:
        print(f"Error: {e}")
        return False

# # Kullanım örneği:
# website_url = "https://example.com"  # Hedef web sitesinin URL'sini değiştirin

# ssl_check(website_url)