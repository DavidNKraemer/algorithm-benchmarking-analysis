#lang racket
;;;http://people.cs.aau.dk/~normark/prog3-03/html/notes/higher-order-fu-note-searchfu.html
(define (linear-search lst key)
  (cond ((null? lst) #f)
        ((equal? key (car lst)) #t)
        (else (linear-search (cdr lst) key))))

(define (linear-search-time lst key)
  (let ([before (current-inexact-milliseconds)])
  (cond ((null? lst) #f)
        ((equal? key (car lst)) #t)
        (else (linear-search (cdr lst) key)))
    (let ([after (current-inexact-milliseconds)])
        (- after before))))

(define linear-search-time-file
  (lambda (input-file output-file)
    (linear-search-time '(2 3) 2)
    ;everytime scheme runs a new procedure it takes longer 
    ;because of configuration
    (let kernel ([source (open-input-file input-file)]
                 [target (open-output-file output-file)])
      (let ([nextval (read source)])
        (cond 
          [(eof-object? nextval) 
           (close-input-port source)
           (close-output-port target)]
          [else 
           (write (linear-search-time (cdr nextval) (car nextval)) target)
           (display "," target)
           (write (length nextval) target)
           (display "linear-search" target)
           (display "," target)
           (display "R" target)
           (display "," target)
           (display "Scheme" target)
           (newline target)
           (kernel source target)])))))