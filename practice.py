from bs4 import BeautifulSoup

html_doc = """
<html><head><title>Hello World</title></head>
<body><h2>Test Header</h2>
<p>This is a test.</p>
<a id="link1" href="/my_link1">Link 1</a>
<a id="link2" href="/my_link2">Link 2</a>
<p>Hello, <b class="boldtext">Bold Text</b></p>
</body></html>
"""

soup = BeautifulSoup(html_doc, 'html.parser')

# Print the hole html file
print(soup.prettify())

# Get title in html
title_tag = soup.title
print(title_tag)
print("title: " + str(soup.title.string))
print()

a_tags = soup.find_all('a')
for tag in a_tags:
    # print(tag.string)
    print(tag.get('href'))
print()

# tags = soup.find_all(['a', 'b'])
tags = soup.find_all(['a', 'b'], limit=2)
print(tags)