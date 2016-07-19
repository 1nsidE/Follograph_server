//
// Created by inside on 4/6/16.
//

#ifndef HTTPSERVER_INSTAGRAMMETHODS_H
#define HTTPSERVER_INSTAGRAMMETHODS_H

namespace Instagram{
    namespace Users{
        static constexpr const char* users = "/v1/users/";
        static constexpr const char* recent_media = "/media/recent";
        static constexpr const char* search = "search";
        static constexpr const char* self_liked = "self/media/liked";
    }

    namespace Relationships{
        static constexpr const char* users = "/v1/users/";
        static constexpr const char* follows  = "self/follows";
        static constexpr const char* followed_by = "self/followed-by";
        static constexpr const char* requested_by = "self/requested-by";
        static constexpr const char* relationship = "/relationship/";
    }

    namespace Media{
        static constexpr const char* get_media = "/v1/media/";
        static constexpr const char* get_media_shortcode = "/v1/media/shortcode/";
        static constexpr const char* media_search = "/v1/media/search/";

    }

    namespace Comments{
        static constexpr const char* TEXT_ARG = "text";
        
        static constexpr const char* media = "/v1/media/";
        static constexpr const char* comments = "/comments/";
    }

    namespace Likes{
        static constexpr const char* media = "/v1/media/";
        static constexpr const char* likes = "/likes";
    }

    namespace Tags{
        static constexpr const char* tags = "/v1/tags/";
        static constexpr const char* tags_search = "search/";
        static constexpr const char* recent_media = "/media/recent/";
    }

    namespace Locations{
        static constexpr const char* locations = "/v1/locations/";
        static constexpr const char* recent_media = "/media/recent/";
        static constexpr const char* search = "search/";
    }
}


#endif //HTTPSERVER_INSTAGRAMMETHODS_H
