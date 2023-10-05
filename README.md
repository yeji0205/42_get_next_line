# 42_get_next_line
<p>
이 프로젝트를 통해서 운영체제에서 파일을 어떻게 열고, 읽고, 닫는지와 운영체제가 어떻게 프로그래밍 언어와 상호작용하는지를 이해할 수 있다.
  <br>
이 프로젝트는 텍스트 파일에서 한번에 한 라인을 리턴하는 함수를 코딩하는 것으로 구성되어 있다.
</p>

|          |         |
| -------- | ------- |
| Program name  | get_next_line   |
| Prototype | char *get_next_line(int fd);     |
| Parameters    | fd: The file descriptor to read from   |
| Turn in files    | get_next_line.c, get_next_line_utils.c , get_next_line.h   |
| Return value   | Read line: correct behavior. NULL: there is nothing else to read, or an error occurred   |
| External functs.     | malloc, free,  read   |
| Description    | Write a function that returns a line read from a file descriptor   |

  <h2> Thoughts of cases </h2>
<br>
<img src="https://github.com/yeji0205/42_get_next_line/assets/40808293/d5c16673-1ac6-4884-a270-4d4b557b48f5" width=50%>
<h2>!!주의할 점!! </h2>
- 메모리 free()하고 프리한 메모리는 NULL 포인터로 할당해야 한다. 댕글링 포인터가 되지 않도록. 즉 삭제된 메모리 부분을 포인팅하지 않도록. 
- static 메모리를 업데이트 할때(리딩한 스트링과 합치거나, 리턴한 라인이 삭제된) 이전의 static 메모리를 free()하고 다시 할당하는 것을 잊지말자! 안그러면 Memory Leak 난다. 왜냐하면 업데이트된 새로운 포인터에 할당이 되었기 때문에, 이전의 메모리가 그대로 남아있게 됨으로.
