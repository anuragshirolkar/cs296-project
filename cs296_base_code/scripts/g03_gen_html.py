import sys
import re
f=open('./doc/g03_report.tex')
f1=open('./doc/g03_project_report.html','w')
a=f.read()
ans=""
ans+="<!DOCTYPE html>"
ans+="<html><title>CS296 Report - G03</title>"



req=re.findall(r'\\section{TIMING}.*\\section{PROFILING}',a,re.DOTALL)
print(req)
req=re.sub(r'(\\section{PROFILING})', r'', req[0])
req=re.sub(r'(\\section{)(.*)(})', r'<h1>\2</h1><p>', req)
req=re.sub(r'(\\subsection{)(.*)(})', r'</p><h2>\2</h2><p>', req)
req=re.sub(r'(\\subsubsection{)(.*)(})', r'</p><h3>\2</h3><p>', req)
req=re.sub(r'(\\end{center})', r'</div>',req)
req=re.sub(r'(\\begin{center})', r'</p><div style="text-align:center">',req)
req=re.sub(r'(\\includegraphics\[scale)(.*)(\]{)(.*)(})', r'<img src="../plots/\4">', req)
req=re.sub(r'(\\\\)', r'<br>',req)
req=re.sub(r'(\\begin{itemize})', r'<ol>',req)
req=re.sub(r'(\\end{itemize})', r'</ol>', req)
req=re.sub(r'(\\item)(.*)',r'<li>\2</li>', req)
#print(req)
ans+=req


ans+="<style>"
ans+="body{font-face:sans-serif;font-size:10;padding:10%;}"
ans+="h1, h2, h3, h4{text-align:center;}"
ans+="</style>"

ans+="</html>"
f1.write(ans)


#print(a)
