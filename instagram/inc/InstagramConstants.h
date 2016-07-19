#ifndef INSTAGRAM_CONSTANTS
#define INSTAGRAM_CONSTANTS

namespace Instagram{
    static constexpr const char* INSTAGRAM_HOST = "api.instagram.com";
    static constexpr const char* AUTH_CODE_GRANT_TYPE = "authorization_code";
    static constexpr const char* AUTH_TOKEN_ARG = "access_token";
    static constexpr const char* GET_AUTH_CODE = "/oauth/access_token";
    static constexpr const char* SELF = "self";
    static constexpr const char* QUERY_ARG = "q";   
    static constexpr const char* LAT_ARG = "lat";
    static constexpr const char* LNG_ARG = "lng";
    static constexpr const char* DST_ARG = "distance";
    static constexpr const char* COUNT_ARG = "count";
    static constexpr const char* MIN_ID_ARG = "min_id";
    static constexpr const char* MAX_ID_ARG = "max_id";
    static constexpr const char* MAX_LIKE_ID = "max_like_id";
}

#endif
