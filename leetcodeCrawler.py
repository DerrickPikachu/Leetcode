from selenium import webdriver
from selenium.webdriver.chrome.options import Options
from account import account

# if __name__ == "__main__":
#     options = Options()
#     # Used in practice, not in test
#     # options.add_argument('--headless')
#     # options.add_argument('--no-sandbox')
#     driver = webdriver.Chrome('./chromedriver', chrome_options=options)
#     driver.set_window_size(1024, 960)
#     # 使用 driver 開起 https://tw.yahoo.com
#     driver.get("https://tw.yahoo.com")
#     # 使用 xpath 找到搜尋欄並填入 hello world
#     inputs = driver.find_element_by_xpath('//*[@id="UHSearchBox"]')
#     inputs.send_keys("hello world")
#     # 找到送出鍵並點擊
#     driver.find_element_by_xpath('//*[@id="UHSearchWeb"]').click()
#     # 將目前頁面存到 yahoo.png
#     driver.save_screenshot('yahoo.png')


class Leetcode:
    def __init__(self):
        self.home_page = "https://leetcode.com/"
        self.login_page = "https://leetcode.com/accounts/login/"
        options = Options()
        # options.add_argument('--headless')
        # options.add_argument('--no-sandbox')

        print("Open Chrome")
        self.driver = webdriver.Chrome('./chromedriver', chrome_options=options)
        self.driver.set_window_size(1024, 960)

    def goToLeetcode(self):
        print("Go to leetcode")
        self.driver.get(self.home_page)

    def login(self):
        print("Go to login page")
        self.driver.get(self.login_page)

        print("Write the account information")
        usernameInput = self.driver.find_element_by_xpath('//*[@id="id_login"]')
        passwordInput = self.driver.find_element_by_xpath('//*[@id="id_password"]')
        usernameInput.send_keys(account['login'])
        passwordInput.send_keys(account['password'])

        print("Click the login button")
        submitButton = self.driver.find_element_by_xpath('//*[@id="signin_btn"]/div/span')
        submitButton.click()


if __name__ == "__main__":
    leetcode = Leetcode()
    leetcode.login()