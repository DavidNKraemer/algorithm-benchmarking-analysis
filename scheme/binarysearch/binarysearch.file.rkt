#lang racket
;;;http://www.codecodex.com/wiki/Binary_search#Scheme
(define (binary-search-helper list key low high)
  (let ((mid (quotient (+ low high) 2)))
    (cond ((> low high) -1)
          ((= (list-ref list mid) key) mid)
          ((> (list-ref list mid) key) (binary-search-helper list key low (- mid 1)))
          (else (binary-search-helper list key (+ mid 1) high)))))

(define binary-search
  (lambda (lst key)
      (binary-search-helper lst key 0 (length lst))))

(define binary-search-time
  (lambda (lst key)
    (let ([before (current-inexact-milliseconds)])
      (binary-search-helper lst key 0 (length lst))
      (let ([after (current-inexact-milliseconds)])
        (- after before)))))

(define binary-search-time-file
  (lambda (input-file output-file)
    (binary-search-time '(2 3) 2)
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
           (write (binary-search-time (cdr nextval) (car nextval)) target)
           (display "," target)
           (write (length nextval) target)
           (display "binary-search" target)
           (display "," target)
           (display "R" target)
           (display "," target)
           (display "Scheme" target)
           (newline target)
           (kernel source target)])))))