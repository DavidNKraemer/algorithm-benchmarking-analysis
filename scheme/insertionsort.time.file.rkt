#lang racket

;;;https://gist.github.com/miyukino/5652107
(define (insert L M)
  (if (null? L) M
      (if (null? M) L
          (if (< (car L) (car M))
              (cons (car L) (insert (cdr L) M))
              (cons (car M) (insert (cdr M) L))))))
(define (insertionsort L)
  (if (null? L) '()
      (insert (list (car L)) (insertionsort (cdr L)))))

(define insertionsort-time
  (lambda (List)
    (let ([before (current-inexact-milliseconds)])
      (insertionsort List)
      (let ([after (current-inexact-milliseconds)])
        (- after before)))))

(define insertionsort-time-file
  (lambda (input-file output-file)
    (insertionsort-time '(2 3))
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
           (write (insertionsort-time nextval) target)
           (display "," target)
           (write (length nextval) target)
           (newline target)
           (kernel source target)])))))
