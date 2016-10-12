InstagramCpp:
----------------
Implementation of the Instagram REST API client in C++.

Project is under active development.

Supported API's:
----------------
All official endpoints are supported.

Usage Example:
----------------
``` cpp
...
#include<InstagramClient.h>
...

int main(){
    /***
    retrieving OAuth response code
    ***/

    Instagram::InstagramClient inst_client{};
    Instagram::AuthorizationToken auth_token = inst_client.exchange_code(code, client_id, client_secret, redirect_uri);
   
    if(!auth_token){
        std::cerr << "Failed to retrieve authorization token, reason : " << auth_token.get_error_message() << std::endl;
        return 1;
    }
    
    std::cout << "User with name : " << auth_token.get_user_name() << " authenticated" << std::endl;

    inst_client.set_auth_token(auth_token.get_auth_token());
    
    Instagram::MediaEntries media_entries = inst_client.get_recent_media();
    if(!media_entries){
    	std::cerr << "Failed to retrieve recent media, reason : " << media_entries.get_error_message() << std::endl;
    	return 1;
    }
   
    for(const auto& media : media_entries){
        std::cout << media.get_caption() << "\n";
        std::cout << "likes count : "  << media.get_like_count() << "\n";
        std::cout << "comments count " << media.get_comments_count() << "\n"<< std::endl; 
    }

    return 0;
}
```

Dependencies:
----------------
JsonCpp - https://github.com/open-source-parsers/jsoncpp

GnuTLS - https://www.gnutls.org

Build Instructions:
----------------

Linux and MacOSX:
----------------

Tested on Linux with 4.5 kernel and MacOSX 10.11 with gcc and clang.

    cmake .
    make

You will find shared library with headers file divided into 2 folders in "lib" folder.

Windows:
----------------

Experimental Windows builds is supported, tested with:
* Visual Studio 2015 Update 2
* GnuTLS 3.4.9 x64
* jsoncpp 1.7.7 (d8cd848ede)

Detailed steps:

1. Download GNUTLS from here: ftp://ftp.gnutls.org/gcrypt/gnutls/w32/
   As of Oct2016, version 3.4.9 w64 is fine.
2. Extract the content a directory, e.g. C:\Program Files\gnutls-3.4.9-w64
3. generate .lib and .exp from .def file as explained here: https://wiki.inspircd.org/GnuTLS_SSL_Module_Under_Windows
   e.g execute from a Developer Command Prompt for Visual Studio as Administrator:
    
   C:\Program Files\gnutls-3.4.9-w64\bin>lib /def:libgnutls-30.def /nologo /machine:x64
      Creating library libgnutls-30.lib and object libgnutls-30.exp

4. Copy the .lib file from /bin/ to /lib/ and rename it to: gnutls.lib (removing the trailing '-30').
5. compile the jsoncpp library from: https://github.com/open-source-parsers/jsoncpp
   - Use CMake 3.3.0, click Configure button, then as generator select Visual Studio 14 2015 Win64, then click Generate. At this point you created the .sln files.
   - Open the jsoncpp.sln file, Rebuild Solution. 
   - Then install by building the INSTALL project (remember to run VS as Administrator). Now jsoncpp headers and binaries would be installed by 
   default under C:/Program Files/jsoncpp/.

6. Using CMake open the CMakeLists.txt file for InstagramCpp
   - Click Configure, select the genration of project files for Visual Studio 14 2015 Win64.
   - The configuration will fail, nevertheless two variables with no values appears.
   - Set GNUTLS_USERPROVIDED_PATH to point to where GNUTls has been copied previously (e.g. C:/Program Files/gnutls-3.4.9-w64);
   - Set JSONCPP_USERPROVIDED_PATH to point to where it has been installed (e.g. C:\Program Files\jsoncpp);
   - Click configure again, it will succeed;
   - Click Generate to create the project files;
   - Open the instagramcpp.sln, build and enjoy.


