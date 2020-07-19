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

        print("loading cookie...")
        cookies = pickle.load(open('cookiesAfter.pkl', 'rb'))
        for cookie in cookies:
            self.driver.add_cookie(cookie)

        time.sleep(5)
        print("refresh..")
        self.driver.get(self.home_page)

        try:
            self.driver.find_element_by_id('nav-user-app')
        except:
            print("session is invalid or not exist")
            print("try to login")
            self.__login()

    def __login(self):
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
        time.sleep(5)
        print("Go to submission")
        usr = self.driver.find_element_by_xpath('//*[@id="nav-user-app"]/span')
        usr.click()
        time.sleep(1)
        submit = self.driver.find_element_by_xpath('//*[@id="nav-user-app"]/span/ul/div[2]/li[2]/div/div[3]')
        submit.click()

    def __readCode(self):
        time.sleep(5)
        myCode = self.driver.find_element_by_xpath('//*[@id="ace"]/div/div[3]/div/div[3]')
        print(myCode.text)
        print(type(myCode.text))
        self.driver.back()

    def getCode(self):
        # // *[ @ id = "submission-list-app"] / div / table / tbody / tr[x] / td[3] / a
        time.sleep(5)
        print("Get code")
        head = '//*[@id="submission-list-app"]/div/table/tbody'
        tail = '/td[3]/a'
        tbody = self.driver.find_element_by_xpath(head)
        tr = tbody.find_element_by_tag_name('tr')
        tableSize = tbody.size['height'] // tr.size['height']
        print("This pages table size is: {}".format(tableSize))

        btn = self.driver.find_element_by_xpath(head + '/tr[1]' + tail)
        btn.click()
        self.__readCode()


if __name__ == "__main__":
    leetcode = Leetcode()
    leetcode.goToLeetcode()
    leetcode.goToSubmission()
    leetcode.getCode()
    pickle.dump(leetcode.driver.get_cookies(), open('cookiesAfter.pkl', 'wb'))
