all:
	touch README.md
	git init
	git add README.md
	git commit -m "first commit"
	git remote add origin https://github.com/anuragshirolkar/cs296-project.git project
	git push -u origin master
