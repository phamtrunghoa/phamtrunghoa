#!/usr/bin/python3

import sys, os

def help():
    print("pyCodeGen: ./pyCodeGen.py [-option] [dir]\n")
    print("    Use to generate include file into inc folder.\n")
    print("    Change the current directory to 'dir'\n")
    print("    If the directory is not found, an error will be occur\n")
    print("    Options:")
    print("      --client               generate client file\n")
    print("      --server               generate server file\n")
    print("      --server <path>        generate server file into specific folder\n")
    print("      --client <path>        generate client file into specific folder\n")
    print("    *Hint: Use 'pwd' command to get the path of your directory and copy it.")
    print("    Eg: ./pyCodeGen.py --client /home/poh6hc/Desktop/ServerClient/Client/inc\n")
    print("    Use the command without directory path will generate the code into default path\n")
    print("    The default path is to follow your machine directory into your inc file")
    print("    Eg: ./pyCodeGen.py --client is the same as ./pyCodeGen.py --client /home/poh6hc/Desktop/ServerClient/Client/inc")
def inc_server():
    print("*-----------------------------*")
    print("*---- Generating Server.h ----*")
    print("*-----------------------------*")
    file1 = open(os.path.dirname(os.path.abspath(__file__)) + "/Server/inc/server.h", "w")
    file1.seek(0, 0)
    file1.write("#include <stdio.h>\n")
    file1.write("#include <stdlib.h>\n")
    file1.write("#include <string.h>\n")
    file1.write("#include <unistd.h>\n")
    file1.write("#include <sys/socket.h>\n")
    file1.write("#include <sys/types.h>\n")
    file1.write("#include <netinet/in.h>\n")
    file1.write("#include <arpa/inet.h>\n")
    file1.write("#include <iostream>\n")
    file1.write("\n")
    file1.write("using namespace std;")
    file1.write("\n")
    file1.write("\n")
    file1.write("#define PORT 4444")
    file1.write("\n")
    file1.write("\n")
    file1.write("class Server")
    file1.write("\n")
    file1.write("{")
    file1.write("\n")
    file1.write("public:")
    file1.write("\n")
    file1.write("   ")
    file1.write("int sockfd, ret;")
    file1.write("\n")
    file1.write("   ")
    file1.write("struct sockaddr_in serverAddr;")
    file1.write("\n")
    file1.write("\n")
    file1.write("   ")
    file1.write("int newSocket;")
    file1.write("\n")
    file1.write("   ")
    file1.write("struct sockaddr_in newAddr;")
    file1.write("\n")
    file1.write("\n")
    file1.write("   ")
    file1.write("socklen_t addr_size;")
    file1.write("\n")
    file1.write("   ")
    file1.write("char buffer[1024];")
    file1.write("\n")
    file1.write("\n")
    file1.write("   ")
    file1.write("pid_t childpid;")
    file1.write("\n")
    file1.write("\n")
    file1.write("   ")
    file1.write("void vCreateServer();")
    file1.write("\n")
    file1.write("   ")
    file1.write("void vConnectClient();")
    file1.write("\n")
    file1.write("};")
    file1.close()
    print("Done")
def inc_client():
    print("*-----------------------------*")
    print("*---- Generating Client.h ----*")
    print("*-----------------------------*")
    file1 = open(os.path.dirname(os.path.abspath(__file__)) + "/Client/inc/client.h", "w")
    file1.seek(0, 0)
    file1.write("#include <stdio.h>\n")
    file1.write("#include <stdlib.h>\n")
    file1.write("#include <string.h>\n")
    file1.write("#include <unistd.h>\n")
    file1.write("#include <sys/socket.h>\n")
    file1.write("#include <sys/types.h>\n")
    file1.write("#include <netinet/in.h>\n")
    file1.write("#include <arpa/inet.h>\n")
    file1.write("#include <iostream>\n")
    file1.write("\n")
    file1.write("using namespace std;")
    file1.write("\n")
    file1.write("\n")
    file1.write("#define PORT 4444")
    file1.write("\n")
    file1.write("\n")
    file1.write("class Client")
    file1.write("\n")
    file1.write("{")
    file1.write("\n")
    file1.write("public:")
    file1.write("\n")
    file1.write("   ")
    file1.write("int clientSocket, ret;")
    file1.write("\n")
    file1.write("\n")
    file1.write("   ")
    file1.write("struct sockaddr_in serverAddr;")
    file1.write("\n")
    file1.write("   ")
    file1.write("char buffer[1024];")
    file1.write("\n")
    file1.write("\n")
    file1.write("   ")
    file1.write("void vOpenConnect();")
    file1.write("\n")
    file1.write("   ")
    file1.write("void vCommunicateServer();")
    file1.write("\n")
    file1.write("};")
    file1.close()
    print("Done")
def inc_server_path():
    print("*-----------------------------*")
    print("*---- Generating Server.h ----*")
    print("*-----------------------------*")
    file1 = open(sys.argv[i+1] + "/server.h", "w")
    file1.seek(0, 0)
    file1.write("#include <stdio.h>\n")
    file1.write("#include <stdlib.h>\n")
    file1.write("#include <string.h>\n")
    file1.write("#include <unistd.h>\n")
    file1.write("#include <sys/socket.h>\n")
    file1.write("#include <sys/types.h>\n")
    file1.write("#include <netinet/in.h>\n")
    file1.write("#include <arpa/inet.h>\n")
    file1.write("#include <iostream>\n")
    file1.write("\n")
    file1.write("using namespace std;")
    file1.write("\n")
    file1.write("\n")
    file1.write("#define PORT 4444")
    file1.write("\n")
    file1.write("\n")
    file1.write("class Server")
    file1.write("\n")
    file1.write("{")
    file1.write("\n")
    file1.write("public:")
    file1.write("\n")
    file1.write("   ")
    file1.write("int sockfd, ret;")
    file1.write("\n")
    file1.write("   ")
    file1.write("struct sockaddr_in serverAddr;")
    file1.write("\n")
    file1.write("\n")
    file1.write("   ")
    file1.write("int newSocket;")
    file1.write("\n")
    file1.write("   ")
    file1.write("struct sockaddr_in newAddr;")
    file1.write("\n")
    file1.write("\n")
    file1.write("   ")
    file1.write("socklen_t addr_size;")
    file1.write("\n")
    file1.write("   ")
    file1.write("char buffer[1024];")
    file1.write("\n")
    file1.write("\n")
    file1.write("   ")
    file1.write("pid_t childpid;")
    file1.write("\n")
    file1.write("\n")
    file1.write("   ")
    file1.write("void vCreateServer();")
    file1.write("\n")
    file1.write("   ")
    file1.write("void vConnectClient();")
    file1.write("\n")
    file1.write("};")
    file1.close()
    print("Done")
def inc_client_path():
    print("*-----------------------------*")
    print("*---- Generating Client.h ----*")
    print("*-----------------------------*")
    file1 = open(sys.argv[i+1] + "/client.h", "w")
    file1.seek(0, 0)
    file1.write("#include <stdio.h>\n")
    file1.write("#include <stdlib.h>\n")
    file1.write("#include <string.h>\n")
    file1.write("#include <unistd.h>\n")
    file1.write("#include <sys/socket.h>\n")
    file1.write("#include <sys/types.h>\n")
    file1.write("#include <netinet/in.h>\n")
    file1.write("#include <arpa/inet.h>\n")
    file1.write("#include <iostream>\n")
    file1.write("\n")
    file1.write("using namespace std;")
    file1.write("\n")
    file1.write("\n")
    file1.write("#define PORT 4444")
    file1.write("\n")
    file1.write("\n")
    file1.write("class Client")
    file1.write("\n")
    file1.write("{")
    file1.write("\n")
    file1.write("public:")
    file1.write("\n")
    file1.write("   ")
    file1.write("int clientSocket, ret;")
    file1.write("\n")
    file1.write("\n")
    file1.write("   ")
    file1.write("struct sockaddr_in serverAddr;")
    file1.write("\n")
    file1.write("   ")
    file1.write("char buffer[1024];")
    file1.write("\n")
    file1.write("\n")
    file1.write("   ")
    file1.write("void vOpenConnect();")
    file1.write("\n")
    file1.write("   ")
    file1.write("void vCommunicateServer();")
    file1.write("\n")
    file1.write("};")
    file1.close()
    print("Done")
# if (len(sys.argv) == 2 and sys.argv[1] == "--server"):
#     inc_server()
# elif (len(sys.argv) == 2 and sys.argv[1] == "--client"):
#     inc_client()
# elif (len(sys.argv) == 3 and sys.argv[1] == "--server"):
#     inc_server_path()
# elif (len(sys.argv) == 3 and sys.argv[1] == "--client"):
#     inc_client_path()
# elif (len(sys.argv) == 2 and sys.argv[1] == "--help"):
#     help()
# elif (len(sys.argv) > 2):
#     if (argv[1] == "--server" or argv[2] == "--server"):

if (len(sys.argv) > 2):
    for i in range(len(sys.argv) -1):
        if (sys.argv[i] == "--server"):
            if (sys.argv[i+1] == "and"):
                inc_server()
            elif (sys.argv[i+1] != "and"):
                inc_server_path()
        if (sys.argv[i] == "--client"):
            if (sys.argv[i+1] == "and"):
                inc_client()
            elif (sys.argv[i+1] != "and"):
                inc_client_path()
else:
    print("Unrecognize command")
    print("Please try again")
