import requests
from bs4 import BeautifulSoup


class Leetcode:
    def __init__(self):
        pass


    def test(self):
        response = requests.get("https://leetcode.com/pikapikachu/")

        if response.status_code == requests.codes.ok:
            soup = BeautifulSoup(response.text, 'html.parser')

            print(soup.prettify())


if __name__ == "__main__":
    leetcode = Leetcode()
    leetcode.test()