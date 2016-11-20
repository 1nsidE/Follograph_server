#ifndef USER_INFO_H
#define USER_INFO_H

#include "BaseResult.h"

namespace Instagram{

class EXPORT_INSTAGRAM UserInfo : public BaseResult{
public:
    UserInfo();
    UserInfo(const UserInfo& userInfo);
    UserInfo(UserInfo&& userInfo);

    UserInfo(const char* errMsg);
    UserInfo(const std::string& errMsg);

    ~UserInfo();

    UserInfo& operator=(const UserInfo& userInfo);
    UserInfo& operator=(UserInfo&& userInfo);

    const std::string& id() const noexcept;
    const std::string& username() const noexcept;
    const std::string& name() const noexcept;
    const std::string& lastName() const noexcept;
    const std::string& bio() const noexcept;
    const std::string& profilePictureUrl() const noexcept;
    const std::string& website() const noexcept;

    int followedBy() const noexcept;
    int follows() const noexcept;
    int mediaCount() const noexcept;

    void setId(const std::string& id);
    void setUsername(const std::string& username);
    void setName(const std::string& name);
    void setLastName(const std::string& lastName);
    void setBio(const std::string& bio);
    void setProfilePictureUrl(const std::string& profPicUrl);
    void setWebsite(const std::string& website);

    void setFollowedBy(int count);
    void setFollows(int count);
    void setMediaCount(int count);
private:
    std::string m_id{};
    std::string m_username{};
    std::string m_name{};
    std::string m_lastName{};
    std::string m_bio{};
    std::string m_profPicUrl{};
    std::string m_website{};

    int m_followedBy{-1};
    int m_follows{-1};
    int m_mediaCount{-1};
};

}

#endif
