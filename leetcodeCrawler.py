import threading

from selenium.common.exceptions import NoSuchElementException
from selenium import webdriver
from selenium.webdriver.chrome.options import Options
from account import account
from codeRecorder import Recorder
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
        self.__firstProgramUrl = ''
        options = Options()
        options.add_argument('--headless')
        options.add_argument('--no-sandbox')

        self.recorder = Recorder()

        print("Open Chrome")
        self.driver = webdriver.Chrome('./chromedriver', chrome_options=options)
        # self.driver.set_window_size(1024, 960)
        self.driver.maximize_window()

    def getCode(self):
        # // *[ @ id = "submission-list-app"] / div / table / tbody / tr[x] / td[3] / a
        time.sleep(5)
        print("Get code")

        head = '//*[@id="submission-list-app"]/div/table/tbody'
        tail = '/td[3]/a'
        acchead = '//*[@id="submission-list-app"]/div/table/tbody'
        acctail = '/td[3]'

        try:
            while True:
                time.sleep(5)
                for i in range(1, 21):
                    accepted = self.driver.find_element_by_xpath(acchead + '/tr[' + str(i) + ']' + acctail)
                    if accepted.text == "Accepted":
                        btn = self.driver.find_element_by_xpath(head + '/tr[' + str(i) + ']' + tail)
                        btn.click()
                        self.__readCode()
                    time.sleep(3)

                self.driver \
                    .find_element_by_id('submission-list-app') \
                    .find_element_by_class_name('next') \
                    .find_element_by_tag_name('a').click()
        except NoSuchElementException:
            print(NoSuchElementException)
            print("There is no more code, task finish!!\nAnd then you may push your new code")

        self.recorder.saveAll(self.__getCodeId(self.__firstProgramUrl))

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
            self.driver.find_element_by_xpath('//*[@id="nav-user-app"]/span')
        except:
            print("session is invalid or not exist")
            print("try to login")
            self.__login()

    def goToSubmission(self):
        time.sleep(5)
        print("Go to submission")
        usr = self.driver.find_element_by_xpath('//*[@id="nav-user-app"]/span')
        usr.click()
        time.sleep(1)
        submit = self.driver.find_element_by_xpath('//*[@id="nav-user-app"]/span/ul/div[2]/li[2]/div/div[3]')
        submit.click()

    def __getCodeId(self, url : str):
        entrys = url.split('/')
        return entrys[len(entrys) - 2]

    def __readCode(self):
        time.sleep(5)

        if self.__firstProgramUrl == '':
            self.__firstProgramUrl = self.driver.current_url
        if self.__getCodeId(self.driver.current_url) == self.recorder.preCodeId:
            print("Reach the previous record, stop the process.")
            return

        problemTitle = self.driver.find_element_by_xpath('//*[@id="submission-app"]/div/div[1]').text
        print("Problem Name: " + problemTitle)

        if not self.recorder.checkExist(problemTitle):
            parent = self.driver.find_element_by_xpath('//*[@id="ace"]/div')
            child = self.driver.find_element_by_xpath('//*[@id="ace"]/div/div[3]/div/div[3]/div[1]')
            entrySize = parent.size['height'] // child.size['height']
            language = self.driver.find_element_by_xpath('//*[@id="result_language"]')

            target = '//*[@id="ace"]/div/div[3]/div/div[3]/div['
            code = ''

            print("Reading code....")
            try:
                for i in range(1, entrySize + 1):
                    line = self.driver.find_element_by_xpath(target + str(i) + ']')
                    code += line.text + '\n'
            except:
                print("Index out of bound, but is ok..., program continue")

            print("Start to write the code into the file...")
            task = threading.Thread(target=self.recorder.record, args=(code, problemTitle, language.text,))
            task.start()
        else:
            print("Has already been saved in local")

        print()
        self.driver.back()

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


if __name__ == "__main__":
    leetcode = Leetcode()
    leetcode.goToLeetcode()
    leetcode.goToSubmission()
    leetcode.getCode()
    pickle.dump(leetcode.driver.get_cookies(), open('cookiesAfter.pkl', 'wb'))
