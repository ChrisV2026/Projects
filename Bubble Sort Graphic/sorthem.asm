%include "asm_io.inc"

SECTION .data

row1: db "          o|o",10,0
row2: db "         oo|oo",10,0
row3: db "        ooo|ooo",10,0
row4: db "       oooo|oooo",10,0
row5: db "      ooooo|ooooo",10,0
row6: db "     oooooo|oooooo",10,0
row7: db "    ooooooo|ooooooo",10,0
row8: db "   oooooooo|oooooooo",10,0
row9: db "  ooooooooo|ooooooooo",10,0
flat: db "XXXXXXXXXXXXXXXXXXXXXXX",10,0
argc: db "Incorrect number of command line arguments",10,0
argv: db "Incorrect command line argument",10,0
x1: dd 4
start: db "Initial Configuration",10,0
ending: db "Final Configuration",10,0
arr: dd 0,0,0,0,0,0,0,0,0

SECTION .bss
  num resd 1
  change resd 1
SECTION .text
  global asm_main

asm_main:
  enter 0,0
  pusha
  mov eax, dword [ebp+8]
  cmp eax, dword 2
  jne err1
  mov ebx, dword [ebp+12]
  mov eax, dword [ebx+4]

  mov bl, byte [eax]
  cmp bl, '1'
  jbe err2

  cmp bl, '9'
  ja err2

  sub bl, '0'
  mov ecx, 0
  mov cl, bl
  mov bl, byte [eax+1]
  cmp bl, byte 0
  jne err2

  mov [change], dword 0

  mov [num], ecx
  push dword [num]
  push arr
  call rconf
  mov eax, start
  call print_string

  call showp
  call sorthem

  mov eax, ending
  call print_string
  call showp
  add esp,8
  jmp end


sorthem:
  enter 0,0
  pusha

  mov ebx, dword [ebp+8]    ;;global name arr
  mov ecx, dword [ebp+12]  ;;global name num

  cmp ecx, 1
  je sorthem_end
  sub ecx, 1
  push ecx
  add ecx,1
  add ebx, 4
  push ebx
  sub ebx, 4
  call sorthem
  pop eax
  pop eax

  mov eax, 4
  mul ecx
  mov ecx, eax

  mov edx, 0
  mov [change], dword 0
  loop2:
    sub ecx, 4
    cmp edx, ecx
    je loop_end
    add ecx, 4

    mov eax, dword [ebx+edx]
    cmp eax, dword [ebx+4+edx]
    ja loop_end

    mov eax, dword [ebx+edx]
    push eax
    mov eax, dword [ebx+4+edx]
    push eax

    pop dword [ebx+edx]
    pop dword [ebx+4+edx]

    mov [change], dword 1

    add edx, 4
    jmp loop2

  loop_end:
    cmp dword [change], dword 1
    jne sorthem_end
    push dword [num]
    push arr
    call showp
    add esp, 8
  sorthem_end:

  popa
  leave
  ret


showp:
  enter 0,0
  pusha
  mov ebx, dword [ebp+8]   ;;array
  mov eax, dword [ebp+12]  ;;size
  mul dword [x1]
  mov ecx, eax
  loop:
    sub ecx, 4
    cmp dword[ebx+ecx], 1
    je p1
    cmp dword[ebx+ecx], 2
    je p2
    cmp dword[ebx+ecx], 3
    je p3
    cmp dword[ebx+ecx], 4
    je p4
    cmp dword[ebx+ecx], 5
    je p5
    cmp dword[ebx+ecx], 6
    je p6
    cmp dword[ebx+ecx], 7
    je p7
    cmp dword[ebx+ecx], 8
    je p8
    cmp dword[ebx+ecx], 9
    je p9
    p1:
      mov eax, row1
      jmp print
    p2:
      mov eax, row2
      jmp print
    p3:
      mov eax, row3
      jmp print
    p4:
      mov eax, row4
      jmp print
    p5:
      mov eax, row5
      jmp print
    p6:
      mov eax, row6
      jmp print
    p7:
      mov eax, row7
      jmp print
    p8:
      mov eax, row8
      jmp print
    p9:
      mov eax, row9
      jmp print
    print:
      call print_string
      cmp ecx, 0
      jne loop
  mov eax, flat
  call print_string
  call read_char
  popa
  leave
  ret

err1:
  mov eax, argc
  call print_string
  jmp end

err2:
  mov eax, argv
  call print_string
  jmp end

end:
  popa
  leave
  ret
