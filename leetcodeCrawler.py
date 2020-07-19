from selenium import webdriver
from selenium.webdriver.chrome.options import Options
from account import account
import time
import pickle

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
        self.submission = "https://leetcode.com/submissions/#/1"
        options = Options()
        # options.add_argument('--headless')
        # options.add_argument('--no-sandbox')

        print("Open Chrome")
        self.driver = webdriver.Chrome('./chromedriver', chrome_options=options)
        self.driver.set_window_size(1024, 960)

    def goToLeetcode(self):
        self.driver.implicitly_wait(5)
        print("Go to leetcode")
        self.driver.get(self.home_page)

        cookies = pickle.load(open('cookiesAfter.pkl', 'rb'))
        for cookie in cookies:
            self.driver.add_cookie(cookie)

        time.sleep(5)
        self.driver.get(self.home_page)

        try:
            self.driver.find_element_by_id('nav-user-app')
        except:
            self.login()

    def login(self):
        self.driver.implicitly_wait(5)
        print("Go to login page")
        # self.driver.get(self.login_page)
        signIn = self.driver.find_element_by_xpath(
            '//*[@id="landing-page-app"]/div/div[1]/div[3]/div[1]/div/div/div[2]/div/a[5]'
        )
        signIn.click()

        time.sleep(5)
        print("Write the account information")
        usernameInput = self.driver.find_element_by_xpath('//*[@id="id_login"]')
        passwordInput = self.driver.find_element_by_xpath('//*[@id="id_password"]')
        usernameInput.send_keys(account['login'])
        passwordInput.send_keys(account['password'])

        time.sleep(5)
        print("Click the login button")
        submitButton = self.driver.find_element_by_xpath('//*[@id="signin_btn"]/div/span')
        submitButton.click()

        input("Please press any key to continue")
        self.driver.implicitly_wait(5)
        pickle.dump(self.driver.get_cookies(), open('cookiesAfter.pkl', 'wb'))

    def goToSubmission(self):
        print("Go to submission")
        self.driver.get(self.submission)

    def getCode(self):
        # // *[ @ id = "submission-list-app"] / div / table / tbody / tr[1] / td[3] / a
        print("Get code")
        bodyPath = '//*[@id="submission-list-app"]/div/table/tbody'
        tbody = self.driver.find_element_by_xpath(bodyPath)
        tr = tbody.find_element_by_tag_name('tr')
        print(tbody.size)
        print(tr.size)
        print(tbody.size['height'] // tr.size['height'])


if __name__ == "__main__":
    leetcode = Leetcode()
    leetcode.goToLeetcode()
    pickle.dump(leetcode.driver.get_cookies(), open('cookiesAfter.pkl', 'wb'))
