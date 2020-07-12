import requests
from account import account
from bs4 import BeautifulSoup
from requests_toolbelt import MultipartEncoder


class Leetcode:
    def __init__(self):
        self.session = requests.Session()
        self.user_agent = "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/83.0.4103.116 Safari/537.36"
        self.home_page = "https://leetcode.com"
        self.login_page = "https://leetcode.com/accounts/login"

    def login(self):
        cookies = self.session.get(self.home_page).cookies
        csrftoken = ''
        for cookie in cookies:
            if cookie.name == 'csrftoken':
                csrftoken = cookie.value

        header = {
            'User-Agent': self.user_agent,
            'Connection': 'keep-alive',
            'Referer': 'https://leetcode.com/accounts/login/',
            'origin': self.home_page
        }
        request_param = {
            'csrfmiddlewaretoken': csrftoken,
            'login': account['login'],
            'password': account['password'],
            'next': 'problems'
        }

        multipartData = MultipartEncoder(request_param)
        header['Content-Type'] = multipartData.content_type
        response = self.session.post(self.login_page, headers=header, data=multipartData, timeout=10, allow_redirects=False)
        is_login = response.cookies.get("LEETCODE_SESSION") is not None

        if is_login:
            print("login success")
        else:
            print("fail")

    def test(self):
        response = self.session.post("https://leetcode.com/accounts/login/", data=account)
        # response = s.get("https://leetcode.com/submissions/#/1")

        if response.status_code == requests.codes.ok:
            soup = BeautifulSoup(response.text, 'html.parser')

            print(soup.prettify())
        else:
            print(response)


if __name__ == "__main__":
    leetcode = Leetcode()
    leetcode.login()
